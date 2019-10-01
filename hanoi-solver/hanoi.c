#include <stdio.h>
#include <stdlib.h>

void hanoi_solver(unsigned long long disks, unsigned char source, unsigned char intermediate, unsigned char target)
{
    if(disks != 0)
    {
        hanoi_solver(disks - 1, source, target, intermediate);
        printf("From %c to %c\n", source, target);
        hanoi_solver(disks - 1, intermediate, source, target);
    }
}

int main(int argc, char **argv)
{
    unsigned long long movs;
    unsigned char source, intermediate, target;
    
    if(argc == 5)
    {
        movs = strtoull(argv[1], NULL, 10);
        source = *(unsigned char *)argv[2];
        intermediate = *(unsigned char *)argv[3];
        target = *(unsigned char*)argv[4];

        printf("Minimum amount of movs: %u\n", (1 << movs) - 1);
        hanoi_solver(movs, source, intermediate, target);

    }else {
        fprintf(stderr, "usage %s <disks><source><intermediate><target>\n", *argv);
        return 1;
    }

    return 0;
}
