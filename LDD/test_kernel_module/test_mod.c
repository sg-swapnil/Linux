// testmod.c - simple char device with dynamic memory allocation
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/slab.h>      // for kmalloc and kfree
#include <linux/uaccess.h>   // for copy_to_user / copy_from_user

#define DEVICE_NAME "testmod"
#define BUF_SIZE 256

static int major;          // dynamically assigned major number
static char *kernel_buffer; // dynamically allocated memory
static size_t data_size = 0;

static ssize_t test_read(struct file *file, char __user *user_buf, size_t count, loff_t *ppos)
{
    size_t bytes_to_read;

    if (*ppos >= data_size)
        return 0; // EOF

    bytes_to_read = min(count, data_size - *ppos);

    if (copy_to_user(user_buf, kernel_buffer + *ppos, bytes_to_read))
        return -EFAULT;

    *ppos += bytes_to_read;
    pr_info("testmod: read %zu bytes\n", bytes_to_read);
    return bytes_to_read;
}
static ssize_t test_write(struct file *file, const char __user *user_buf, size_t count, loff_t *ppos)
{
    size_t bytes_to_write = min(count, (size_t)(BUF_SIZE - 1));

    if (copy_from_user(kernel_buffer, user_buf, bytes_to_write))
        return -EFAULT;

    kernel_buffer[bytes_to_write] = '\0';
    data_size = bytes_to_write;

    pr_info("testmod: received from user: %s\n", kernel_buffer);
    return bytes_to_write;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .read = test_read,
    .write = test_write,
};

static int __init testmod_init(void)
{
    kernel_buffer = kmalloc(BUF_SIZE, GFP_KERNEL);
    if (!kernel_buffer) {
        pr_err("testmod: failed to allocate memory\n");
        return -ENOMEM;
    }

    major = register_chrdev(0, DEVICE_NAME, &fops);//chrdev - char chrdev
    if (major < 0) {
        pr_err("testmod: failed to register char device\n");
        kfree(kernel_buffer);
        return major;
    }

    pr_info("testmod: loaded with major %d\n", major);
    pr_info("testmod: create device node with: sudo mknod /dev/%s c %d 0\n", DEVICE_NAME, major);
    return 0;
}

static void __exit testmod_exit(void)
{
    unregister_chrdev(major, DEVICE_NAME);//chrdev - char device 
    kfree(kernel_buffer);
    pr_info("testmod: unloaded and memory freed\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("You");
MODULE_DESCRIPTION("Simple kernel module using dynamic memory allocation");

module_init(testmod_init);
module_exit(testmod_exit);

