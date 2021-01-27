cmd_/home/eren/kernel_test/Module.symvers := sed 's/ko$$/o/' /home/eren/kernel_test/modules.order | scripts/mod/modpost  -a   -o /home/eren/kernel_test/Module.symvers -e -i Module.symvers   -T -
