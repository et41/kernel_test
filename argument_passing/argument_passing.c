/*
 * Demonstrates command line argument passing to a module
 */

#include <linux/module.h>
#include  <linux/moduleparam.h>
#include  <linux/kernel.h>
#include  <linux/init.h>
#include  <linux/stat.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Eren");

static short int myshort = 1 ;
static int myint = 3000;
static char *mystring = "aaa";
static int myintArray[2] = {1, 2};
static int arr_argc = 0;

module_param(myshort, short,  S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshort, "A short integer");
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(myint, "An Integer");
module_param(mystring, charp, 0000);
MODULE_PARM_DESC(mystring, "A character string");

module_param_array(myintArray, int, &arr_argc, 0000);
MODULE_PARM_DESC(myintArray, "An array of integers");


static int __init argument_passing_init(void) 
{
	int i;
	printk(KERN_INFO "myshort : %hd\n", myshort);
	printk(KERN_INFO "myint is : %d\n", myint);
	printk(KERN_INFO "mystring is : %s\n", mystring);
	for(i = 0; i < (sizeof(myintArray) / sizeof(int) ); i++)
       	{
		printk(KERN_INFO "myintArray[%d] = %d\n", i, myintArray[i] );
	}
	printk(KERN_INFO "got %d arguments for myintArray.\n", arr_argc);
	return 0;
}	

static void __exit argument_passing_exit(void)
{
	printk(KERN_INFO "GOOOBYEE WORLD!!!\n");
}

module_init(argument_passing_init);
module_exit(argument_passing_exit);



