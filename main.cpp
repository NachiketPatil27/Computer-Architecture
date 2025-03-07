#include <iostream>
#include <unordered_map>
#include <fstream> 
#include <cstring> 
#include <ctype.h>
#include <bitset>
#include <vector>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

//function to convert binary string to hexadecimal string
string bin_to_hex(string bin) 
{ 
    //mapping binary to hexadecimal
    bin = string(bin.length() % 4 ? 4 - bin.length() % 4 : 0, '0') + bin; 
    unordered_map<string, char> hex_dict = { 
        {"0000", '0'}, {"0001", '1'}, {"0010", '2'}, {"0011", '3'}, 
        {"0100", '4'}, {"0101", '5'}, {"0110", '6'}, {"0111", '7'}, 
        {"1000", '8'}, {"1001", '9'}, {"1010", 'A'}, {"1011", 'B'}, 
        {"1100", 'C'}, {"1101", 'D'}, {"1110", 'E'}, {"1111", 'F'} 
    }; 
    //converting binary to hexadecimal
    string hex = ""; 
    for (int i = 0; i < bin.length(); i += 4) 
    { 
        string group = bin.substr(i, 4); 
        hex += hex_dict[group]; 
    } 
    return hex; 
}

//function to convert decimal to hexadecimal
string decToHexa(long long n)
{
    string ans = "";
    while (n != 0) {
        int rem = 0;
        char ch;
        rem = n % 16;
        if (rem < 10) {
            ch = rem + 48;
        }
        else {
            ch = rem + 55;
        }
        ans = ch+ans;
        n = n / 16;
    }
    return ans;
}

//function to convert signed decimal to a bitset(12 bits)
bitset<12> dec2bin_12(unsigned n)
{
    bitset<12>p;
    int i;
    for(i=11;i>=0;i--)
    {
        if(n>0)
        {
        if(n%2==1)
        p.set(i);
        n=n/2;
        }
       
    }
    
    return p;

}
//function to convert signed decimal to a bitset(12 bits)
bitset<12> comp_2_12(long n)
{
    long x=n;
    if(n<0)
    x=-n;
    long pow=1;
    
    for(int i=1;i<=12;i++)
    pow=pow*2;
    if(n<0)
    {
        x=pow-x;
    }
    if((n>(pow/2-1))||(n<(-pow/2)))
        {
            cout<<"invalid input"<<endl;
            exit(0);
        }
    return dec2bin_12(x);
}

//function to convert signed decimal to a bitset(20 bits)
bitset<20> dec2bin_20(unsigned n)
{
    bitset<20>p;
    int i;
    for(i=19;i>=0;i--)
    {
        if(n>0)
        {
        if(n%2==1)
        p.set(i);
        n=n/2;
        }
       
    }
    
    return p;

}
//function to convert signed decimal to a bitset(20 bits)
bitset<20> comp_2_20(long n)
{
    long x=n;
    if(n<0)
    x=-n;
    long pow=1;
    
    for(int i=1;i<=20;i++)
    pow=pow*2;
    if(n<0)
    {
        x=pow-x;
    }
    if((n>(pow/2-1))||(n<(-pow/2)))
        {
            cout<<"invalid input"<<endl;
            exit(0);
        }
    return dec2bin_20(x);
}

int main()
{
    //store the basic instruction codes for each format in unordered_map
    //creating an unordered_map to store R_format basic instruction codes (opcode,funct3,funct7)
    unordered_map<string,vector<string> >R_format;
    R_format["add"]={"0110011","000","0000000"};
    R_format["and"]={"0110011","111","0000000"};
    R_format["or"]={"0110011","110","0000000"};
    R_format["sll"]={"0110011","001","0000000"};
    R_format["slt"]={"0110011","010","0000000"};
    R_format["sra"]={"0110011","101","0100000"};
    R_format["srl"]={"0110011","101","0000000"};
    R_format["sub"]={"0110011","000","0100000"};
    R_format["xor"]={"0110011","100","0000000"};
    R_format["mul"]={"0110011","000","0000001"};
    R_format["div"]={"0110011","100","0000001"};
    R_format["rem"]={"0110011","110","0000001"};

    //creating an unordered_map to store S_format basic instruction codes (opcode,funct3)
    unordered_map<string,vector<string> >S_format;
    S_format["sb"]={"0100011","000"};
    S_format["sw"]={"0100011","010"};
    S_format["sd"]={"0100011","011"};
    S_format["sh"]={"0100011","001"};

    //creating an unordered_map to store U_format basic instruction codes (opcode)
    unordered_map<string,vector<string> >U_format;
    U_format["auipc"]={"0010111"};
    U_format["lui"]={"0110111"};

    //creating an unordered_map to store I_format basic instruction codes (opcode,funct3)
    unordered_map<string,vector<string> > I_format;
    I_format["addi"] = {"0010011","000"};
    I_format["andi"] = {"0010011","111"};
    I_format["ori"] = {"0010011","110"};
    I_format["lb"] = {"0000011","000"};
    I_format["lh"] = {"0000011","001"};
    I_format["lw"] = {"0000011","010"};
    I_format["ld"] = {"0000011","011"};
    I_format["jalr"] = {"1100111","000"};

    //creating an unordered_map to store SB_format basic instruction codes (opcode,funct3)
    unordered_map<string,vector<string>>SB_format;
    SB_format["beq"]={"1100011","000"};
    SB_format["bne"]={"1100011","001"};
    SB_format["bge"]={"1100011","101"};
    SB_format["blt"]={"1100011","100"};

    //creating an unordered_map to store UJ_format basic instruction codes (opcode)
    unordered_map<string,string>UJ_format;
    UJ_format["jal"] = "1101111";

    //opening input_file.asm
    ifstream file("input_file.asm"); 

    //storing each line of the input in a vector of strings
    vector<string>input;
    string line; 
    if (file.is_open()) 
    {  
        while (getline(file, line)) 
        {
            input.push_back(line);
        } 

        file.close(); 
    }

    int size = input.size();
   
    //checking if the input file has .data and .text segments
    string data = ".data";
    string text = ".text";
    auto it_data = find(input.begin(),input.end(),data);
    auto it_text = find(input.begin(),input.end(),text);
    int start = 0;
    //if .data segment is present, start from the next line
    if(it_data != input.end())
    {
        int i = 0;
        while(input[i]!=text) i++;
        start = i+1;
    }
    else if (input[start]==text) start = start+1;
    
    //creating a label table to store the labels and their corresponding program counter values
    unordered_map<string,int>label_pc;
    int PC_LABEL = 0;
    for(int i=start;i<size;i++)
    {
        string line = input[i];
        string label = "";
        int j = 0;
        //extracting the label from the line
        while(line[j]!=' ' && line[j]!=':' && j<line.size())
        {
            label += line[j];
            j++;
        }
        //if the label is not present in the instruction set, store the label and its program counter value
        if(R_format.find(label)==R_format.end()&&S_format.find(label)==S_format.end()&&SB_format.find(label)==SB_format.end()&&I_format.find(label)==I_format.end()&&U_format.find(label)==U_format.end()&&UJ_format.find(label)==UJ_format.end())
        {
            label_pc[label]=PC_LABEL;
        }
        else PC_LABEL+=4;
    }

    //removing the labels from the input
    for(int i = 0;i<input.size();)
    {
        string line = input[i].substr(0,input[i].size()-1);
        if(label_pc.find(line)!=label_pc.end())
        {
            auto it = find(input.begin(),input.end(),line+':');
            input.erase(it);
        }
        else
        {
            i++;
        }
    }

    //opening the output.mc file
    ofstream MyFile("output.mc");

    //storing the data in data segment
    long address=10000000;
    //creating an unordered_map to store the assembler directives and their corresponding sizes
    unordered_map<string,int>assembler_dir;
    assembler_dir["word"]=4;
    assembler_dir["dword"]=8;
    assembler_dir["byte"]=1;
    assembler_dir["asciiz"]=1;
    assembler_dir["half"]=2;
    //converting the data from data segment to machine code
    for(int i=it_data-input.begin()+1;i<start-1;i++)
    {
        string line=input[i];
        size_t dir = line.find('.');
        int j=dir+1;
        string directive="";
        while(line[j]!=' ')
        {
            directive+=line[j];
            j++;
        }
        j++;
        //converting the data to machine code
        if(directive!="asciiz")
        {
            long long num=0;
            //iterating through the data
            while(j<line.size())
            {
                if(isdigit(line[j]))
                    num=num*10+(int(line[j]-'0'));
                if(line[j]==',')
                {
                    string machine_code="0x"+to_string(address)+ " "+"0x"+decToHexa(num);
                    MyFile<<machine_code<<endl;
                    address+=assembler_dir[directive];
                    num=0;
                }
                j++;
                //if the data is at the end of the line
                if(j==line.size())
                {
                    string machine_code="0x"+to_string(address)+" "+"0x"+decToHexa(num);
                    MyFile<<machine_code<<endl;
                    address+=assembler_dir[directive];
                    num=0;
                }
            }
        }
        //converting the asciiz data to machine code
        else
        {
            j++;
            while(line[j]!='\"')
            {
                int ascii=int(line[j]);
                string machine_code="0x"+to_string(address)+" "+"0x"+decToHexa(ascii);
                MyFile<<machine_code<<endl;
                address+=assembler_dir[directive];
            }
        }
    }

    //converting the instructions from text segment to machine code
    int PC = 0; // program counter
    //iterating through the instructions in the text segment
    for(int i=start;i<input.size();i++)
    {
        string line = input[i];
        int j =0;
        if(line[j] == ' ') j++;
        string instruction = "";
        string machine_code="";
        string output = "";
        while(line[j]!= ' ')
        {
            instruction += line[j];
            j++;
        }
        //For R-format instructions (add,and,or,sll,slt,sra,srl,sub,xor,mul,div,rem)
        if(R_format.find(instruction)!=R_format.end())
        {
            //getting opcode
            string opcode = R_format[instruction][0];

            //getting funct3
            string funct3 = R_format[instruction][1];

            //getting funct7
            string funct7 = R_format[instruction][2];

            //getting rd
            j++;
            int reg = 0;
            while(line[j]!=',')
            {
                if(isdigit(line[j]))
                {
                    reg = reg*10 + (int(line[j]-'0'));
                }
                j++;
            }
            //converting the register number to a 5-bit binary string
            bitset<5> rd_bits(reg);
            string rd = rd_bits.to_string();
            
            //getting rs1
            j++;
            reg = 0;
            while(line[j]!=',')
            {
                if(isdigit(line[j]))
                {
                    reg = reg*10 + (int(line[j]-'0'));
                }
                j++;
            }
            //converting the register number to a 5-bit binary string
            bitset<5> rs1_bits(reg);
            string rs1 = rs1_bits.to_string();

            //getting rs2
            j++;
            reg = 0;
            //iterating through the line to get the register number
            while(j<line.size())
            {
                if(isdigit(line[j]))
                {
                    reg = reg*10 + (int(line[j]-'0'));
                }
                j++;
            }
            //converting the register number to a 5-bit binary string
            bitset<5> rs2_bits(reg);
            string rs2 = rs2_bits.to_string();
            
            //getting machine code
            string machine_code_bin = funct7 + rs2 + rs1 + funct3 + rd + opcode;
            if(PC!=0)machine_code = "0x"+decToHexa(PC)+ " 0x" + bin_to_hex(machine_code_bin);
            else machine_code = "0x0 0x" + bin_to_hex(machine_code_bin);
            //writing the machine code to the output.mc file
            MyFile << machine_code << " , " << line << " # " << opcode << "-" << funct3 << "-" << funct7 << "-" << rd << "-" << rs1 << "-" << rs2 << "-NULL" << endl;
        }

        //For S-format instructions (sb,sw,sd,sh)
        else if(S_format.find(instruction)!=S_format.end())
        {
            //getting opcode
            string opcode = S_format[instruction][0];

            //getting funct3
            string funct3 = S_format[instruction][1];

            //getting rs1
            j++;
            int reg = 0;
            while(line[j]!=',')
            {
                if(isdigit(line[j]))
                {
                    reg = reg*10 + (int(line[j]-'0'));
                }
                j++;
            }
            //converting the register number to a 5-bit binary string
            bitset<5> rs2_bits(reg);
            string rs2 = rs2_bits.to_string();

            //getting immediate value
            j++;
            int immed = 0;
            int neg = 0;
            while(line[j]!='(')
            {
                 if(isdigit(line[j]))
                {
                    immed = immed*10 + (int(line[j]-'0'));
                }
                if(line[j]=='-')
                {
                    neg = 1;
                }
                j++;
            }
            //converting the immediate value to a 12-bit binary string
            if(neg==1) immed *= -1;
            bitset<12>imm_bit=comp_2_12(immed);
            string imm=imm_bit.to_string();
            reverse(imm.begin(),imm.end());

            //getting rs1
            j++;
            reg=0;
            while(line[j]!=')')
            {
                if(isdigit(line[j]))
                {
                    reg = reg*10 + (int(line[j]-'0'));
                }
                j++;
            }
            //converting the register number to a 5-bit binary string
            bitset<5> rs1_bits(reg);
            string rs1 = rs1_bits.to_string();

            //getting machine code
            string machine_code_bin = imm.substr(0,7) + rs2 + rs1 + funct3 + imm.substr(7,5) + opcode;
            if(PC!=0)machine_code = "0x"+decToHexa(PC)+ " 0x" + bin_to_hex(machine_code_bin);
            else machine_code = "0x0 0x" + bin_to_hex(machine_code_bin);
            //writing the machine code to the output.mc file
            MyFile << machine_code << " , " << line << " # " << opcode << "-" << funct3 << "-NULL-" << "NULL" << "-" << rs1 << "-" << rs2 << "-" << imm << endl;
            
        }

        //For I-format instructions (addi,andi,ori,lb,ld,lh,lw,jalr)
        else if(I_format.find(instruction)!=I_format.end())
        {
            //getting opcode
            string opcode = I_format[instruction][0];

            //getting funct3
            string funct3 = I_format[instruction][1];

            //for addi,andi,ori,jalr
            if(opcode == "0010011" || opcode == "1100111")
            {
                //getting rd
                j++;
                int reg = 0;
                while(line[j]!=',')
                {
                    if(isdigit(line[j]))
                    {
                        reg = reg*10 + (int(line[j]-'0'));
                    }
                    j++;
                }
                bitset<5> rd_bits(reg);
                string rd = rd_bits.to_string();

                //getting rs1
                j++;
                reg = 0;
                while(line[j]!=',')
                {
                    if(isdigit(line[j]))
                    {
                        reg = reg*10 + (int(line[j]-'0'));
                    }
                    j++;
                }
                bitset<5> rs1_bits(reg);
                string rs1 = rs1_bits.to_string();

                //getting immediate value
                j++;
                int immed = 0;
                int neg = 0;
                //iterating through the line to get the immediate value
                while(j!= input[i].size())
                {
                    if(isdigit(line[j]))
                    {
                        immed = immed*10 + (int(line[j]-'0'));
                    }
                    if(line[j]=='-')
                    {
                        neg = 1;
                    }
                    j++;
                }
                //converting the immediate value to a 12-bit binary string
                if(neg==1) immed *= -1;
                string imm;
                imm = comp_2_12(immed).to_string();
                reverse(imm.begin(),imm.end());

                //getting machine code
                string machine_code_bin = imm + rs1 + funct3 + rd + opcode;
                if(PC!=0)machine_code = "0x"+decToHexa(PC)+ " 0x" + bin_to_hex(machine_code_bin);
                else machine_code = "0x0 0x" + bin_to_hex(machine_code_bin);
                //writing the machine code to the output.mc file
                MyFile << machine_code << " , " << line << " # " << opcode << "-" << funct3 << "-NULL-" << rd << "-" << rs1 << "-NULL-" << imm << endl;


            }
            //for lb,lh,lw,ld
            else if (opcode == "0000011")
            {
                //getting rd
                j++;
                int reg = 0;
                while(line[j]!=',')
                {
                    if(isdigit(line[j]))
                    {
                        reg = reg*10 + (int(line[j]-'0'));
                    }
                    j++;
                }
                bitset<5> rd_bits(reg);
                string rd = rd_bits.to_string();

                //getting immediate value
                j++;
                int immed = 0;
                int neg = 0;
                while(line[j]!='(')
                {
                    if(isdigit(line[j]))
                    {
                        immed = immed*10 + (int(line[j]-'0'));
                    }
                    if(line[j]=='-')
                    {
                        neg = 1;
                    }
                    j++;
                }
                if(neg==1) immed *= -1;
                string imm = comp_2_12(immed).to_string();
                reverse(imm.begin(),imm.end());
                
                //getting rs1
                j++;
                reg = 0;
                while(line[j]!=')')
                {
                    if(isdigit(line[j]))
                    {
                        reg = reg*10 + (int(line[j]-'0'));
                    }
                    j++;
                }
                bitset<5> rs1_bits(reg);
                string rs1 = rs1_bits.to_string();

                //getting machine code
                string machine_code_bin = imm + rs1 + funct3 + rd + opcode;
                if(PC!=0)machine_code = "0x"+decToHexa(PC)+ " 0x" + bin_to_hex(machine_code_bin);
                else machine_code = "0x0 0x" + bin_to_hex(machine_code_bin);
                MyFile << machine_code << " , " << line << " # " << opcode << "-" << funct3 << "-NULL-" << rd << "-" << rs1 << "-NULL-" << imm << endl;
            }
        }
        
        else if (U_format.find(instruction)!=U_format.end())
        {
            //getting opcode
            string opcode = U_format[instruction][0];

            //getting rd
            j++;
            int reg = 0;
            while(line[j]!=',')
            {
                if(isdigit(line[j]))
                {
                    reg = reg*10 + (int(line[j]-'0'));
                }
                j++;
            }
            bitset<5> rd_bits(reg);
            string rd = rd_bits.to_string();

            //getting immediate value
            j++;
            int immed = 0;
            int neg = 0;
            while(j<line.size())
            {
                if(isdigit(line[j]))
                {
                    immed = immed*10 + (int(line[j]-'0'));
                }
                if(line[j]=='-')
                {
                    neg = 1;
                }
                j++;
            }
            if(neg==1) immed *= -1;
            string imm = "";
            bitset<20>imm_bit=comp_2_20(immed);
            imm=imm_bit.to_string();
            reverse(imm.begin(),imm.end());

            //getting machine code
            string machine_code_bin = imm + rd + opcode;
            if(PC!=0)machine_code = "0x"+decToHexa(PC)+ " 0x" + bin_to_hex(machine_code_bin);
            else machine_code = "0x0 0x" + bin_to_hex(machine_code_bin);
            MyFile << machine_code << " , " << line << " # " << opcode << "-NULL-NULL-" << rd << "-NULL-NULL-" << imm << endl;
        }
        
        else if (SB_format.find(instruction)!=SB_format.end())
        {
            //getting opcode
            string opcode = SB_format[instruction][0];

            //getting funct3
            string funct3 = SB_format[instruction][1];

            //getting rs1
            j++;
            int reg = 0;
            while(line[j]!=',')
            {
                if(isdigit(line[j]))
                {
                    reg = reg*10 + (int(line[j]-'0'));
                }
                j++;
            }
            bitset<5> rs1_bits(reg);
            string rs1 = rs1_bits.to_string();

            //getting rs2
            j++;
            reg = 0;
            while(line[j]!=',')
            {
                if(isdigit(line[j]))
                {
                    reg = reg*10 + (int(line[j]-'0'));
                }
                j++;
            }
            bitset<5> rs2_bits(reg);
            string rs2 = rs2_bits.to_string();

            //getting immediate value from label table
            j++;
            string label = "";
            while(j<input[i].size())
            {
                label+=line[j];
                j++;
            }
            int immed = (label_pc[label] - PC)/2;
            string imm;
            imm = comp_2_12(immed).to_string();
            reverse(imm.begin(),imm.end());

            //getting machine code
            string machine_code_bin = imm[0] + imm.substr(2,6) + rs2 + rs1 + funct3 + imm.substr(8,4) + imm[1] + opcode;
            if(PC!=0)machine_code = "0x"+decToHexa(PC)+ " 0x" + bin_to_hex(machine_code_bin);
            else machine_code = "0x0 0x" + bin_to_hex(machine_code_bin);
            MyFile << machine_code << " , " << line << " # " << opcode << "-" << funct3 << "-NULL-" << "NULL" << "-" << rs1 << "-" << rs2 << "-" << imm << endl;
        }
        
        else if (UJ_format.find(instruction)!=UJ_format.end())
        {
            //getting opcode
            string opcode = UJ_format[instruction];

            //getting rd
            j++;
            int reg = 0;
            while(line[j]!=',')
            {
                if(isdigit(line[j]))
                {
                    reg = reg*10 + (int(line[j]-'0'));
                }
                j++;
            }
            bitset<5> rd_bits(reg);
            string rd = rd_bits.to_string();

            //getting immediate value from label table
            j++;
            string label = "";
            while(j<input[i].size())
            {
                label+=line[j];
                j++;
            }
            int immed = (label_pc[label] - PC)/2;
            string imm;
            imm = comp_2_20(immed).to_string();
            reverse(imm.begin(),imm.end());

            //getting machine code
            string machine_code_bin = imm[0] + imm.substr(10,10) + imm[9] + imm.substr(1,8) + rd + opcode;
            if(PC!=0)machine_code = "0x"+decToHexa(PC)+ " 0x" + bin_to_hex(machine_code_bin);
            else machine_code = "0x0 0x" + bin_to_hex(machine_code_bin);
            MyFile << machine_code << " , " << line << " # " << opcode << "-NULL-NULL-" << rd << "-NULL-NULL-" << imm << endl;
        }
        PC+=4; //incrementing pc
    }
    //closing output.mc file
    MyFile.close();
    return 0;
}
