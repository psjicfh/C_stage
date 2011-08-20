Linux的帧缓冲设备

帧缓冲（framebuffer）是 Linux 为显示设备提供的一个接口，把显存抽象后的一种设备，他允许上层应用程序在

图形模式下直接对显示缓冲区进行读写操作。这种操作是抽象的，统一的。用户不必关心物理显存的位置、换页机

制等等具体细节。这些都是由Framebuffer 设备驱动来完成的。帧缓冲驱动的应用广泛，在 linux 的桌面系统中，

Xwindow 服务器就是利用帧缓冲进行窗口的绘制。尤其是通过帧缓冲可显示汉字点阵，成为 Linux汉化的唯一可行

方案。

帧缓冲设备对应的设备文件为/dev/fb*，如果系统有多个显示卡，Linux 下还可支持多个帧缓冲设备，最多可达 32

个，分别为/dev/fb0 到/dev/fb31，而/dev/fb 则为当前缺省的帧缓冲设备，通常指向/dev/fb0。当然在嵌入式系

统中支持一个显示设备就够了。帧缓冲设备为标准字符设备，主设备号为29，次设备号则从0到31。分别对

应/dev/fb0-/dev/fb31。

通过/dev/fb，应用程序的操作主要有这几种：

1．读/写（read/write）/dev/fb：相当于读/写屏幕缓冲区。例如用 cp /dev/fb0 tmp 命令可将当前屏幕的内容

拷贝到一个文件中，而命令 cp tmp > /dev/fb0 则将图形文件tmp显示在屏幕上。

2．映射（map）操作：由于 Linux 工作在保护模式，每个应用程序都有自己的虚拟地址空间，在应用程序中是不能

直接访问物理缓冲区地址的。为此，Linux 在文件操作 file_operations 结构中提供了 mmap 函数，可将文件的内

容映射到用户空间。对于帧缓冲设备，则可通过映射操作，可将屏幕缓冲区的物理地址映射到用户空间的一段虚拟

地址中，之后用户就可以通过读写这段虚拟地址访问屏幕缓冲区，在屏幕上绘图了。

3．I/O控制：对于帧缓冲设备，对设备文件的 ioctl操作可读取/设置显示设备及屏幕的参数，如分辨率，显示颜色

数，屏幕大小等等。ioctl 的操作是由底层的驱动程序来完成的。


在应用程序中，操作/dev/fb的一般步骤如下：

1．打开/dev/fb设备文件。

2．用 ioctrl 操作取得当前显示屏幕的参数，如屏幕分辨率，每个像素点的比特数。根据屏幕参数可计算屏幕缓冲

区的大小。

3．将屏幕缓冲区映射到用户空间（mmap）。

4．映射后就可以直接读写屏幕缓冲区，进行绘图和图片显示了。

典型程序段如下：

------------------------
#include <linux/fb.h>

int main()

{  

int fbfd = 0;

struct fb_var_screeninfo vinfo;

struct fb_fix_screeninfo finfo;

long int screensize = 0;

/*打开设备文件*/

fbfd = open("/dev/fb0", O_RDWR);

/*取得屏幕相关参数*/

ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo);  

ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo);

/*计算屏幕缓冲区大小*/

screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

/*映射屏幕缓冲区到用户地址空间*/

fbp=(char*)mmap(0,screensize,PROT_READ|PROT_WRITE,MAP_SHARED, fbfd, 0);

/*下面可通过 fbp指针读写缓冲区*/

……

/*释放缓冲区，关闭设备*/

munmap(fbp, screensize);

close(fbfd);

}
-----------------------
ioctl操作

ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo)

获取fb_var_screeninfo结构的信息，在linux/include/linux/fb.h定义。

ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo)

获取fb_fix_screeninfon结构的信息。在linux/include/linux/fb.h定义。

fbfd为设备文件号。

-----------------------
mmap函数

功能描述：

mmap函数是unix/linux下的系统调用

mmap将一个文件或者其它对象映射进内存。文件被映射到多个页上，如果文件的大小不是所有页的大小之和，最后

一个页不被使用的空间将会清零。munmap执行相反的操作，删除特定地址区域的对象映射。

基于文件的映射，在mmap和munmap执行过程的任何时刻，被映射文件的st_atime可能被更新。如果st_atime字段在

前述的情况下没有得到更新，首次对映射区的第一个页索引时会更新该字段的值。用PROT_WRITE 和 MAP_SHARED标

志建立起来的文件映射，其st_ctime 和 st_mtime

在对映射区写入之后，但在msync()通过MS_SYNC 和 MS_ASYNC两个标志调用之前会被更新。

用法：

#include <sys/mman.h>

void *mmap(void *start, size_t length, int prot, int flags,

int fd, off_t offset);

int munmap(void *start, size_t length);

参数：

start：映射区的开始地址。

length：映射区的长度。

prot：期望的内存保护标志，不能与文件的打开模式冲突。是以下的某个值，可以通过or运算合理地组合在一起

PROT_EXEC //页内容可以被执行

PROT_READ //页内容可以被读取

PROT_WRITE //页可以被写入

PROT_NONE //页不可访问

flags：指定映射对象的类型，映射选项和映射页是否可以共享。它的值可以是一个或者多个以下位的组合体

MAP_FIXED //使用指定的映射起始地址，如果由start和len参数指定的内存区重叠于现存的映射空间，重叠部分将

会被丢弃。如果指定的起始地址不可用，操作将会失败。并且起始地址必须落在页的边界上。

MAP_SHARED //与其它所有映射这个对象的进程共享映射空间。对共享区的写入，相当于输出到文件。直到msync()

或者munmap()被调用，文件实际上不会被更新。

MAP_PRIVATE //建立一个写入时拷贝的私有映射。内存区域的写入不会影响到原文件。这个标志和以上标志是互斥

的，只能使用其中一个。

MAP_DENYWRITE //这个标志被忽略。

MAP_EXECUTABLE //同上

MAP_NORESERVE //不要为这个映射保留交换空间。当交换空间被保留，对映射区修改的可能会得到保证。当交换空

间不被保留，同时内存不足，对映射区的修改会引起段违例信号。

MAP_LOCKED //锁定映射区的页面，从而防止页面被交换出内存。

MAP_GROWSDOWN //用于堆栈，告诉内核VM系统，映射区可以向下扩展。

MAP_ANONYMOUS //匿名映射，映射区不与任何文件关联。

MAP_ANON //MAP_ANONYMOUS的别称，不再被使用。

MAP_FILE //兼容标志，被忽略。

MAP_32BIT //将映射区放在进程地址空间的低2GB，MAP_FIXED指定时会被忽略。当前这个标志只在x86-64平台上得

到支持。

MAP_POPULATE //为文件映射通过预读的方式准备好页表。随后对映射区的访问不会被页违例阻塞。

MAP_NONBLOCK //仅和MAP_POPULATE一起使用时才有意义。不执行预读，只为已存在于内存中的页面建立页表入口。

fd：有效的文件描述词。如果MAP_ANONYMOUS被设定，为了兼容问题，其值应为-1。

offset：被映射对象内容的起点。

返回说明：

成功执行时，mmap()返回被映射区的指针，munmap()返回0。失败时，mmap()返回MAP_FAILED[其值为(void *)-1]，

munmap返回-1。errno被设为以下的某个值

EACCES：访问出错

EAGAIN：文件已被锁定，或者太多的内存已被锁定

EBADF：fd不是有效的文件描述词

EINVAL：一个或者多个参数无效

ENFILE：已达到系统对打开文件的限制

ENODEV：指定文件所在的文件系统不支持内存映射

ENOMEM：内存不足，或者进程已超出最大内存映射数量

EPERM：权能不足，操作不允许

ETXTBSY：已写的方式打开文件，同时指定MAP_DENYWRITE标志

SIGSEGV：试着向只读区写入

SIGBUS：试着访问不属于进程的内存区
