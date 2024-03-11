module;
#include <string>
#include <vector>
#include <glm/vec3.hpp>
export module data_structures;

export namespace query_builder
{
    struct bvh {
        // keep index of the parent joint
        std::vector<int> joint_parents;
        // keep the names of all the joints
        std::vector<std::string> joint_names;
        // keep the offset to the parent joint
        std::vector<glm::vec3> joint_offsets;
    };
} // namespace query_builder
