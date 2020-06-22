#include <cstdio>
#include <memory>
#include <dhmem/dhmem.h>
#include <array>

struct e_in {
    float A, B, C;
    float x0;
};

struct e_out {
    float y;
    float yp;
};

int main(int argc, char **argv) {
    std::printf("Hello from evaluate\n");

    dhmem::Dhmem dhmem("foobar");

    auto &map = dhmem.map<int, dhmem::vector<int>>("mymap");
    //dhmem::map<int, dhmem::vector<int>> &map = dhmem.container<dhmem::map<int, dhmem::vector<int>>>("mymap");

    auto &vec = dhmem.container<dhmem::vector<int>>("myvec");
    vec.resize(1024);
    for (int i=0; i<1024; ++i) {
        vec[i] = i;
    }

    auto &count = dhmem.simple<int>("mycount");
    count = 1;

    //map[count] = vec;
    //auto pair = std::pair<const int, dhmem::vector<int>>(count, vec);
    //auto &pair = dhmem.simple<map::template value_type>("mypair")(&&count, &&vec);

    map.insert(std::make_pair(count, vec));

    std::printf("vec[100] = %d; count = %d\n", vec[100], count);

    std::getchar();

    std::printf("vec[100] = %d; count = %d\n", vec[100], count);
}
