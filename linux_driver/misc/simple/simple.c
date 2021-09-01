#include <linux/init.h>
#include <linux/module.h>
#include <linux/miscdevice.h> 
#include <linux/fs.h> 

static int bumper_open(struct inode *node, struct file *filp)
{
	printk(KERN_WARNING "open ...!\n");
	return 0;
}

static ssize_t bumper_read(struct file *filp, char __user *buf, size_t size, loff_t *pos)
{
	printk(KERN_WARNING "bumper read\n");
	return 4;
}

struct file_operations bumper_fops =
	{
		.open = bumper_open,
		.read = bumper_read,
};

struct miscdevice bumper_miscdev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "bumper",
	.fops = &bumper_fops,
};

static int bumper_init(void)
{
	misc_register(&bumper_miscdev);
	printk(KERN_INFO "bumper driver enter\n");
	return 0;
}

static void bumper_exit(void)
{
	misc_deregister(&bumper_miscdev);
	printk(KERN_INFO "bumper driver exit\n ");
}

module_init(bumper_init);
module_exit(bumper_exit);

MODULE_AUTHOR("hackin zhao <hackin.zhao@stratosphere.mobi>");
MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("twc clean robot bumper module");
MODULE_ALIAS("twc robot bumper module");
