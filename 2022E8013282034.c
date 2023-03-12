#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/ioport.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("haoranx98");
MODULE_DESCRIPTION("A simple example of request memory.");
MODULE_VERSION("0.01");

static int __init request_mem_region_InitFunc(void);
static void __exit request_mem_region_ExitFunc(void);

unsigned long from = 0xfe000000;
unsigned long num = 0xff;
char* name = "Haoran Xu's IO memory";
int flag = 0;

int __init request_mem_region_InitFunc(void){

	printk("start ally memory.....\n");
	if(request_mem_region(from, num, name)){
		printk("apply IO memory successfully!!!\n");
		flag = 1;
	}else{
		printk("apply IO memory failed!!!\n");
	}
	return 0;

}

void __exit request_mem_region_ExitFunc(void){
	if(flag == 1){
		release_mem_region(from, num);
		printk("release IO memory successfully!!!\n");
	}else{
		printk("Don't need release\n");
	}
}

module_init(request_mem_region_InitFunc);
module_exit(request_mem_region_ExitFunc);

