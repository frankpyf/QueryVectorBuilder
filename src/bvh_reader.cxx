module;
#include <fstream>
#include <string>
#include <iostream>
#include <stack>
export module bvh_reader;
import data_structures;

void split_by_blank(std::string in_str,
            std::vector<std::string>& out_tokens)
{
    //get rid of the blanks
    size_t pos = in_str.find_first_not_of(' ');
    in_str.erase(0, pos);
    while ((pos = in_str.find(' ')) != std::string::npos)
    {
        out_tokens.emplace_back(in_str.substr(0, pos));
        in_str.erase(0, pos + 1);
        
        pos = in_str.find_first_not_of(' ');
        in_str.erase(0, pos);
    }
    out_tokens.emplace_back(in_str);
}

int find(const std::vector<std::string>& joints, const std::string& joint_name)
{
    for(int i = 0; i < joints.size(); ++i)
    {
        if(joint_name == joints[i])
            return i;
    }
    return -1;
}

export namespace query_builder
{
    void parse_bvh_file(const std::string& bvh_file_path, bvh& out_bvh)
    {
        std::string line;
        std::ifstream file(bvh_file_path);
        std::stack<std::string> parent_stack;
        // meta data
        while(std::getline(file, line))
        {
            std::vector<std::string> tokens;
            split_by_blank(line, tokens);
            if(line.find("ROOT") != std::string::npos || line.find("JOINT") != std::string::npos)
            {
                out_bvh.joint_names.push_back(tokens.back());
                int parent_idx = parent_stack.empty() ? -1 : find(out_bvh.joint_names, parent_stack.top());
                out_bvh.joint_parents.push_back(parent_idx);
            }
            else if(line.find("End Site") != std::string::npos)
            {
                out_bvh.joint_names.push_back(parent_stack.top() + "_End");
                int parent_idx = parent_stack.empty() ? -1 : find(out_bvh.joint_names, parent_stack.top());
                out_bvh.joint_parents.push_back(parent_idx);
            }
            else if(line.find("{") != std::string::npos)
            {
                parent_stack.push(out_bvh.joint_names.back());
            }
            else if(line.find("}") != std::string::npos)
            {
                parent_stack.pop();
            }
            else if(line.find("OFFSET") != std::string::npos)
            {
                out_bvh.joint_offsets.emplace_back(std::stof(tokens[1]), std::stof(tokens[2]), std::stof(tokens[3]));
            }
            else if(line.find("MOTION") != std::string::npos)
                break;
        }
        // motion data
        while(std::getline(file, line))
        {
            std::vector<std::string> tokens;
            split_by_blank(line, tokens);
            
        }
        file.close();
        for(const auto& name : out_bvh.joint_names)
        {
            std::cout << name << '\n';
        }
    }
} // namespace query_builder



