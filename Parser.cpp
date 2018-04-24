#include "Parser.h"
#include <bitset>
#include <cmath>
#include <string.h>

Parser::Parser(string filename)
  // Specify a text file containing MIPS assembly instructions. Function
  // checks syntactic correctness of file and creates a list of Instructions.
{
  Instruction i;
  myFormatCorrect = true;

  myLabelAddress = 0x400000;

  ifstream in;
  in.open(filename.c_str());
  if(in.bad()){
    myFormatCorrect = false;
  }
  else{
    string line;
    while( getline(in, line)){
      string opcode("");
      string operand[80];
      int operand_count = 0;

      getTokens(line, opcode, operand, operand_count);

      if(opcode.length() == 0 && operand_count != 0){
        // No opcode but operands
        myFormatCorrect = false;
        break;
      }

      Opcode o = opcodes.getOpcode(opcode); 

      if(o == UNDEFINED){
        // invalid opcode specified
        myFormatCorrect = false; 
        break;
      }
     
      bool success = getOperands(i, o, operand, operand_count);
      if(!success){
        myFormatCorrect = false;
        break;
      }
      string encoding = encode(i);
      i.setEncoding(encoding);

      myInstructions.push_back(i);

    }
  }

  myIndex = 0;
}


Instruction Parser::getNextInstruction()
  // Iterator that returns the next Instruction in the list of Instructions.
{
  if(myIndex < (int)(myInstructions.size())){
    myIndex++;
    return myInstructions[myIndex-1];
  }

  Instruction i;
  return i;

}

void Parser::getTokens(string line,
    string &opcode,
    string *operand,
    int &numOperands)
  // Decomposes a line of assembly code into strings for the opcode field and operands, 
  // checking for syntax errors and counting the number of operands.
{
  // locate the start of a comment
  string::size_type idx = line.find('#');
  if (idx != string::npos) // found a ';'
    line = line.substr(0,idx);
  int len = line.length();
  opcode = "";
  numOperands = 0;

  if (len == 0) return;
  int p = 0; // position in line

  // line.at(p) is whitespace or p >= len
  while (p < len && isWhitespace(line.at(p)))
    p++;
  // opcode starts
  while (p < len && !isWhitespace(line.at(p)))
  {
    opcode = opcode + line.at(p);
    p++;
  }
  //    for(int i = 0; i < 3; i++){
  int i = 0;
  while(p < len){
    while ( p < len && isWhitespace(line.at(p)))
      p++;

    // operand may start
    bool flag = false;
    while (p < len && !isWhitespace(line.at(p)))
    {
      if(line.at(p) != ','){
        operand[i] = operand[i] + line.at(p);
        flag = true;
        p++;
      }
      else{
        p++;
        break;
      }
    }
    if(flag == true){
      numOperands++;
    }
    i++;
  }


  idx = operand[numOperands-1].find('(');
  string::size_type idx2 = operand[numOperands-1].find(')');

  if (idx == string::npos || idx2 == string::npos ||
      ((idx2 - idx) < 2 )){ // no () found
  }
  else{ // split string
    string offset = operand[numOperands-1].substr(0,idx);
    string regStr = operand[numOperands-1].substr(idx+1, idx2-idx-1);

    operand[numOperands-1] = offset;
    operand[numOperands] = regStr;
    numOperands++;
  }



  // ignore anything after the whitespace after the operand
  // We could do a further look and generate an error message
  // but we'll save that for later.
  return;
}

bool Parser::isNumberString(string s)
  // Returns true if s represents a valid decimal integer
{
  int len = s.length();
  if (len == 0) return false;
  if ((isSign(s.at(0)) && len > 1) || isDigit(s.at(0)))
  {
    // check remaining characters
    for (int i=1; i < len; i++)
    {
      if (!isdigit(s.at(i))) return false;
    }
    return true;
  }
  return false;
}


int Parser::cvtNumString2Number(string s)
  // Converts a string to an integer.  Assumes s is something like "-231" and produces -231
{
  if (!isNumberString(s))
  {
    cerr << "Non-numberic string passed to cvtNumString2Number"
      << endl;
    return 0;
  }
  int k = 1;
  int val = 0;
  for (int i = s.length()-1; i>0; i--)
  {
    char c = s.at(i);
    val = val + k*((int)(c - '0'));
    k = k*10;
  }
  if (isSign(s.at(0)))
  {
    if (s.at(0) == '-') val = -1*val;
  }
  else
  {
    val = val + k*((int)(s.at(0) - '0'));
  }
  return val;
}


bool Parser::getOperands(Instruction &i, Opcode o, 
    string *operand, int operand_count)
  // Given an Opcode, a string representing the operands, and the number of operands, 
  // breaks operands apart and stores fields into Instruction.
{

  if(operand_count != opcodes.numOperands(o)){
    return false;
  }

  int rs, rt, rd, imm;
  imm = 0;
  rs = rt = rd = NumRegisters;

  int rs_p = opcodes.RSposition(o);
  int rt_p = opcodes.RTposition(o);
  int rd_p = opcodes.RDposition(o);
  int imm_p = opcodes.IMMposition(o);

  if(rs_p != -1){
    rs = registers.getNum(operand[rs_p]);
    if(rs == NumRegisters){

      return false;
    }
  }

  if(rt_p != -1){
    rt = registers.getNum(operand[rt_p]);
    if(rt == NumRegisters)
      return false;

  }

  if(rd_p != -1){
    rd = registers.getNum(operand[rd_p]);
    if(rd == NumRegisters)
      return false;

  }

  if(imm_p != -1){
    if(isNumberString(operand[imm_p])){  // does it have a numeric immediate field?
      imm = cvtNumString2Number(operand[imm_p]);
      if(((abs(imm) & 0xFFFF0000)<<1))  // too big a number to fit
        return false;
    }
    else{ 
      if(opcodes.isIMMLabel(o)){  // Can the operand be a label?
        // Assign the immediate field an address
        imm = myLabelAddress;
        myLabelAddress += 4;  // increment the label generator
      }
      else  // There is an error
        return false;
    }

  }

  i.setValues(o, rs, rt, rd, imm);
  return true;
}


string Parser::encode(Instruction i)
  // Given a valid instruction, returns a string representing the 32 bit MIPS binary encoding
  // of that instruction.
{
  // Your code here
  OpcodeTable opcTb;
  Opcode op = i.getOpcode();
  string opcStr = "";

  if(opcTb.getInstType(op) == RTYPE){
    opcStr = handleRtype(i);
  }

  else if(opcTb.getInstType(op) == ITYPE){
    opcStr = handleItype(i);
  }

  else if(opcTb.getInstType(op) == JTYPE){
    opcStr = handleJtype(i);
  }
  
  return opcStr;
}

string Parser::cvtInt2Bin(int number, size_t bits){
  if(bits == 16)
    return bitset<16>(number).to_string();
  else if(bits == 26)
    return bitset<26>(number).to_string();
  else if(bits == 5) 
    return bitset<5>(number).to_string();
  else 
    return bitset<5>(number).to_string();
}

string Parser::handleRtype(Instruction i){
  OpcodeTable opcTb;
  string opcStr = "";
  Opcode op = i.getOpcode();
  opcStr = opcTb.getOpcodeField(op);
  int numOperands = opcTb.numOperands(op);
  if(numOperands==1){
    opcStr += "0000000000";
    opcStr += cvtInt2Bin(i.getRD(), 5);
  }
  else if(numOperands==2){
    opcStr += cvtInt2Bin(i.getRS(), 5);
    opcStr += cvtInt2Bin(i.getRT(), 5);
    opcStr += "0000000000";
    opcStr += opcTb.getFunctField(op);
    return opcStr;
   }

  else{
      opcStr+=cvtInt2Bin(i.getRS(), 5);
      opcStr+=cvtInt2Bin(i.getRT(), 5);
      opcStr+=cvtInt2Bin(i.getRD(), 5); 
  }

    if(opcTb.IMMposition(op)==-1)
      opcStr += "00000";
    else 
      opcStr += cvtInt2Bin(i.getImmediate(), 5);
    opcStr += opcTb.getFunctField(op);
  return opcStr;  
}

string Parser::handleItype(Instruction i){
  OpcodeTable opcTb;
  string opcStr = "";
  Opcode op = i.getOpcode();
  opcStr = opcTb.getOpcodeField(op);
  opcStr += cvtInt2Bin(i.getRS(), 5);
  opcStr += cvtInt2Bin(i.getRT(), 5);
  opcStr += cvtInt2Bin(i.getImmediate(), 16);
  return opcStr;
}

string Parser::handleJtype(Instruction i){
  OpcodeTable opcTb;
  string opcStr = "";
  Opcode op = i.getOpcode();
  opcStr = opcTb.getOpcodeField(op);
  opcStr += cvtInt2Bin(i.getImmediate(), 26);
  opcStr += opcTb.getFunctField(op);
  return opcStr;
}
