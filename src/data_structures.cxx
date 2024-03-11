module;
#include <string>
#include <vector>
export module data_structures;

export namespace query_builder
{
    struct offset { 
        float x;
        float y;
        float z;
        offset(float in_x, float in_y, float in_z)
            : x(in_x), y(in_y), z(in_z) {}
    };

    struct bvh {
        // keep index of the parent joint
        std::vector<int> joint_parents;
        // keep the names of all the joints
        std::vector<std::string> joint_names;
        // keep the offset to the parent joint
        std::vector<offset> joint_offsets;
    };
} // namespace query_builder
