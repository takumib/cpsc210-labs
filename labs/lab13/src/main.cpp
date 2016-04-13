#include <iostream>
#include <string>

#include "list.h"
#include "iterator.h"

int main()
{
    int nums[] = {8, 7, 6, 5, 4, 3, 2, 1};
    std::string stars[] = {}; 
    float nums2[] = {};

    List<int> list1;

    for(int i = 0; i < 8; i++) {
        list1.addFirst(nums[i]);
    }

    Iterator<int> itr(&list1);

    while(itr.hasNext()) {
        std::cout << itr.get()->getItem()
                  << std::endl;
        itr.advance();
    }

    return 0;
}
