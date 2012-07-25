#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/wacom_i2c.h>

#ifdef COOR_WORK_AROUND
#include "wacom_i2c_coord_tables.h"

static ssize_t show_attribute(int coordinate,int hand,int rotation,
                              char *buf)
{
  if (coordinate==0)
    return sprintf(buf, "%hd\n", tilt_offsetX[hand][rotation]);
  else
    return sprintf(buf, "%hd\n", tilt_offsetY[hand][rotation]);
}

static ssize_t show_tilt_offset_x_h0_r0(struct device *dev,
                                        struct device_attribute *attr,
                                        char *buf)
{
	return show_attribute(0,0,0,buf);
}

static ssize_t show_tilt_offset_x_h0_r1(struct device *dev,
                                        struct device_attribute *attr,
                                        char *buf)
{
	return show_attribute(0,0,1,buf);
}

static ssize_t show_tilt_offset_x_h0_r2(struct device *dev,
                                        struct device_attribute *attr,
                                        char *buf)
{
	return show_attribute(0,0,2,buf);
}

static ssize_t show_tilt_offset_x_h0_r3(struct device *dev,
                                        struct device_attribute *attr,
                                        char *buf)
{
	return show_attribute(0,0,3,buf);
}

static ssize_t show_tilt_offset_x_h1_r0(struct device *dev,
                                        struct device_attribute *attr,
                                        char *buf)
{
	return show_attribute(0,1,0,buf);
}

static ssize_t show_tilt_offset_x_h1_r1(struct device *dev,
                                        struct device_attribute *attr,
                                        char *buf)
{
	return show_attribute(0,1,1,buf);
}

static ssize_t show_tilt_offset_x_h1_r2(struct device *dev,
                                        struct device_attribute *attr,
                                        char *buf)
{
	return show_attribute(0,1,2,buf);
}

static ssize_t show_tilt_offset_x_h1_r3(struct device *dev,
                                        struct device_attribute *attr,
                                        char *buf)
{
	return show_attribute(0,1,3,buf);
}

static ssize_t show_tilt_offset_y_h0_r0(struct device *dev,
                                        struct device_attribute *attr,
                                        char *buf)
{
	return show_attribute(1,0,0,buf);
}

static ssize_t show_tilt_offset_y_h0_r1(struct device *dev,
                                        struct device_attribute *attr,
                                        char *buf)
{
	return show_attribute(1,0,1,buf);
}

static ssize_t show_tilt_offset_y_h0_r2(struct device *dev,
                                        struct device_attribute *attr,
                                        char *buf)
{
	return show_attribute(1,0,2,buf);
}

static ssize_t show_tilt_offset_y_h0_r3(struct device *dev,
                                        struct device_attribute *attr,
                                        char *buf)
{
	return show_attribute(1,0,3,buf);
}

static ssize_t show_tilt_offset_y_h1_r0(struct device *dev,
                                        struct device_attribute *attr,
                                        char *buf)
{
	return show_attribute(1,1,0,buf);
}

static ssize_t show_tilt_offset_y_h1_r1(struct device *dev,
                                        struct device_attribute *attr,
                                        char *buf)
{
	return show_attribute(1,1,1,buf);
}

static ssize_t show_tilt_offset_y_h1_r2(struct device *dev,
                                        struct device_attribute *attr,
                                        char *buf)
{
	return show_attribute(1,1,2,buf);
}

static ssize_t show_tilt_offset_y_h1_r3(struct device *dev,
                                        struct device_attribute *attr,
                                        char *buf)
{
	return show_attribute(1,1,3,buf);
}

static void set_attribute(int coordinate,int hand,int rotation,
                          const char *buf, size_t size)
{
  short value;
  if (sscanf(buf, "%hd", &value) == 1) {
    if (coordinate==0)
      tilt_offsetX[hand][rotation]=value;
    else
      tilt_offsetY[hand][rotation]=value;
	}
}

static ssize_t set_tilt_offset_x_h0_r0(struct device *dev,
                                       struct device_attribute *attr,
                                       const char *buf, size_t size)
{
  set_attribute(0,0,0,buf,size);
	return size;
}

static ssize_t set_tilt_offset_x_h0_r1(struct device *dev,
                                       struct device_attribute *attr,
                                       const char *buf, size_t size)
{
  set_attribute(0,0,1,buf,size);
	return size;
}

static ssize_t set_tilt_offset_x_h0_r2(struct device *dev,
                                       struct device_attribute *attr,
                                       const char *buf, size_t size)
{
  set_attribute(0,0,2,buf,size);
	return size;
}

static ssize_t set_tilt_offset_x_h0_r3(struct device *dev,
                                       struct device_attribute *attr,
                                       const char *buf, size_t size)
{
  set_attribute(0,0,3,buf,size);
	return size;
}

static ssize_t set_tilt_offset_x_h1_r0(struct device *dev,
                                       struct device_attribute *attr,
                                       const char *buf, size_t size)
{
  set_attribute(0,1,0,buf,size);
	return size;
}

static ssize_t set_tilt_offset_x_h1_r1(struct device *dev,
                                       struct device_attribute *attr,
                                       const char *buf, size_t size)
{
  set_attribute(0,1,1,buf,size);
	return size;
}

static ssize_t set_tilt_offset_x_h1_r2(struct device *dev,
                                       struct device_attribute *attr,
                                       const char *buf, size_t size)
{
  set_attribute(0,1,2,buf,size);
	return size;
}

static ssize_t set_tilt_offset_x_h1_r3(struct device *dev,
                                       struct device_attribute *attr,
                                       const char *buf, size_t size)
{
  set_attribute(0,1,3,buf,size);
	return size;
}

static ssize_t set_tilt_offset_y_h0_r0(struct device *dev,
                                       struct device_attribute *attr,
                                       const char *buf, size_t size)
{
  set_attribute(1,0,0,buf,size);
	return size;
}

static ssize_t set_tilt_offset_y_h0_r1(struct device *dev,
                                       struct device_attribute *attr,
                                       const char *buf, size_t size)
{
  set_attribute(1,0,1,buf,size);
	return size;
}

static ssize_t set_tilt_offset_y_h0_r2(struct device *dev,
                                       struct device_attribute *attr,
                                       const char *buf, size_t size)
{
  set_attribute(1,0,2,buf,size);
	return size;
}

static ssize_t set_tilt_offset_y_h0_r3(struct device *dev,
                                       struct device_attribute *attr,
                                       const char *buf, size_t size)
{
  set_attribute(1,0,3,buf,size);
	return size;
}

static ssize_t set_tilt_offset_y_h1_r0(struct device *dev,
                                       struct device_attribute *attr,
                                       const char *buf, size_t size)
{
  set_attribute(1,1,0,buf,size);
	return size;
}

static ssize_t set_tilt_offset_y_h1_r1(struct device *dev,
                                       struct device_attribute *attr,
                                       const char *buf, size_t size)
{
  set_attribute(1,1,1,buf,size);
	return size;
}

static ssize_t set_tilt_offset_y_h1_r2(struct device *dev,
                                       struct device_attribute *attr,
                                       const char *buf, size_t size)
{
  set_attribute(1,1,2,buf,size);
	return size;
}

static ssize_t set_tilt_offset_y_h1_r3(struct device *dev,
                                       struct device_attribute *attr,
                                       const char *buf, size_t size)
{
  set_attribute(1,1,3,buf,size);
	return size;
}

static DEVICE_ATTR(tilt_offset_x_h0_r0, S_IRUGO | S_IWUSR | S_IWGRP,
			             show_tilt_offset_x_h0_r0, set_tilt_offset_x_h0_r0);
static DEVICE_ATTR(tilt_offset_x_h0_r1, S_IRUGO | S_IWUSR | S_IWGRP,
			             show_tilt_offset_x_h0_r1, set_tilt_offset_x_h0_r1);
static DEVICE_ATTR(tilt_offset_x_h0_r2, S_IRUGO | S_IWUSR | S_IWGRP,
			             show_tilt_offset_x_h0_r2, set_tilt_offset_x_h0_r2);
static DEVICE_ATTR(tilt_offset_x_h0_r3, S_IRUGO | S_IWUSR | S_IWGRP,
			             show_tilt_offset_x_h0_r3, set_tilt_offset_x_h0_r3);
static DEVICE_ATTR(tilt_offset_x_h1_r0, S_IRUGO | S_IWUSR | S_IWGRP,
			             show_tilt_offset_x_h1_r0, set_tilt_offset_x_h1_r0);
static DEVICE_ATTR(tilt_offset_x_h1_r1, S_IRUGO | S_IWUSR | S_IWGRP,
			             show_tilt_offset_x_h1_r1, set_tilt_offset_x_h1_r1);
static DEVICE_ATTR(tilt_offset_x_h1_r2, S_IRUGO | S_IWUSR | S_IWGRP,
			             show_tilt_offset_x_h1_r2, set_tilt_offset_x_h1_r2);
static DEVICE_ATTR(tilt_offset_x_h1_r3, S_IRUGO | S_IWUSR | S_IWGRP,
			             show_tilt_offset_x_h1_r3, set_tilt_offset_x_h1_r3);
static DEVICE_ATTR(tilt_offset_y_h0_r0, S_IRUGO | S_IWUSR | S_IWGRP,
			             show_tilt_offset_y_h0_r0, set_tilt_offset_y_h0_r0);
static DEVICE_ATTR(tilt_offset_y_h0_r1, S_IRUGO | S_IWUSR | S_IWGRP,
			             show_tilt_offset_y_h0_r1, set_tilt_offset_y_h0_r1);
static DEVICE_ATTR(tilt_offset_y_h0_r2, S_IRUGO | S_IWUSR | S_IWGRP,
			             show_tilt_offset_y_h0_r2, set_tilt_offset_y_h0_r2);
static DEVICE_ATTR(tilt_offset_y_h0_r3, S_IRUGO | S_IWUSR | S_IWGRP,
			             show_tilt_offset_y_h0_r3, set_tilt_offset_y_h0_r3);
static DEVICE_ATTR(tilt_offset_y_h1_r0, S_IRUGO | S_IWUSR | S_IWGRP,
			             show_tilt_offset_y_h1_r0, set_tilt_offset_y_h1_r0);
static DEVICE_ATTR(tilt_offset_y_h1_r1, S_IRUGO | S_IWUSR | S_IWGRP,
			             show_tilt_offset_y_h1_r1, set_tilt_offset_y_h1_r1);
static DEVICE_ATTR(tilt_offset_y_h1_r2, S_IRUGO | S_IWUSR | S_IWGRP,
			             show_tilt_offset_y_h1_r2, set_tilt_offset_y_h1_r2);
static DEVICE_ATTR(tilt_offset_y_h1_r3, S_IRUGO | S_IWUSR | S_IWGRP,
			             show_tilt_offset_y_h1_r3, set_tilt_offset_y_h1_r3);

static struct device_attribute *dev_attrs[2][2][4] = {
  { { &dev_attr_tilt_offset_x_h0_r0, &dev_attr_tilt_offset_x_h0_r1,
      &dev_attr_tilt_offset_x_h0_r2, &dev_attr_tilt_offset_x_h0_r3 },
    { &dev_attr_tilt_offset_x_h1_r0, &dev_attr_tilt_offset_x_h1_r1,
      &dev_attr_tilt_offset_x_h1_r2, &dev_attr_tilt_offset_x_h1_r3 } },
  { { &dev_attr_tilt_offset_y_h0_r0, &dev_attr_tilt_offset_y_h0_r1,
      &dev_attr_tilt_offset_y_h0_r2, &dev_attr_tilt_offset_y_h0_r3 },
    { &dev_attr_tilt_offset_y_h1_r0, &dev_attr_tilt_offset_y_h1_r1,
      &dev_attr_tilt_offset_y_h1_r2, &dev_attr_tilt_offset_y_h1_r3 } }
};

int wacom_i2c_create_extended_attributes(struct device *device)
{
  int hand_count     = (MAX_HAND<hand_count)?MAX_HAND:2;
  int rotation_count = (MAX_ROTATION<hand_count)?MAX_ROTATION:4;
  int i,j,k;

  for(i=0;i<2;i++)
  {
    for(j=0;j<hand_count;j++)
    {
      for(k=0;k<rotation_count;k++)
      {
        if (device_create_file(device, dev_attrs[i][j][k]) < 0)
        {
          printk(KERN_ERR "[TSP] Failed to create device file(%s)!\n",
                 dev_attrs[i][j][k]->attr.name);
          return 1;
        }
      }
    }
  }
  return 0;
}

#else

int wacom_i2c_create_extended_attributes(struct device *device)
{
  return 0;
}

#endif
