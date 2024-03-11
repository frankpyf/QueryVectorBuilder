#include <string>
import bvh_reader;
import data_structures;

#define STRING(x) #x
#define XSTRING(x) STRING(x)
static const std::string data_path(XSTRING(DATA_PATH));
int main()
{
    query_builder::bvh my_bvh;
    query_builder::parse_bvh_file(data_path + "/walking.bvh", my_bvh);
    return 0;
}