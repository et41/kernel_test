cmd_/home/eren/kernel_test/helloworld2.ko := ld -r -m elf_x86_64  -z max-page-size=0x200000  --build-id  -T ./scripts/module-common.lds -o /home/eren/kernel_test/helloworld2.ko /home/eren/kernel_test/helloworld2.o /home/eren/kernel_test/helloworld2.mod.o;  true
