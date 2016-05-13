//dma.h

#ifndef DMA_H_
#define DMA_H_
#include <iostream>
class baseDMA{
private:
	char * label;
	int rating;
public:
	baseDMA(const char * l = "null",int r = 0);
	baseDMA(const baseDMA& rs);
	virtual ~baseDMA();
	baseDMA & operator=(const baseDMA & rs);
	friend std::ostream & operator<<(std::ostream &os,const baseDMA &rs);
};

//derived class without DMA 无动态内存分配继承
//no destructor needed 不需要析构函数
//uses implict copy constructor 使用隐式拷贝构造函数
//use implict assignment operator使用能够隐式赋值运算符
class lackDMA : public baseDMA{
private:
	enum {COL_LEN = 40};
	char color[COL_LEN];
public:
	lackDMA(const char * c = "blank", const char * l = "null",int r = 0);
	lackDMA(const char * c, const baseDMA &rs);
	friend std::ostream & operator<<(std::ostream &os, const lackDMA & rs);
};

//derived class with DMA
class hasDMA : public baseDMA{
private:
	char * style;
public:
	hasDMA(const char * s = "none", const char * l = "null", int r = 0);
	hasDMA(const char * s, const baseDMA &rs);
	hasDMA(const hasDMA &rs);
	virtual ~hasDMA();
	hasDMA & operator=(const hasDMA &rs);
	friend std::ostream & operator<<(std::ostream &os, const hasDMA &rs);
};

#endif
