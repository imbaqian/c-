#include <iostream>
#include "dma.h"
#include <cstring>

//baseDMA methods
baseDMA::baseDMA(const char *l,int r){
	label = new char[std::strlen(l) + 1];
	std::strcpy(label, l);
	rating = r;	
}

baseDMA::baseDMA(const baseDMA &rs){
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;	
}
baseDMA::~baseDMA(){
	delete[] label;
}

baseDMA & baseDMA::operator=(const baseDMA &rs){
	if( &rs == this )
		return *this;
	delete[] label;
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}

std::ostream & operator<<(std::ostream &os, const baseDMA &rs){
	os << "Lable: " << rs.label << std::endl;
	os << "Rating: " << rs.rating << std::endl;
	return os;	
}

//derived class without DMA
lackDMA::lackDMA(const char * c, const char *l, int r) : baseDMA(l, r){
	std::strcpy(color, c);
}

lackDMA::lackDMA(const char * c, const baseDMA &rs) : baseDMA(rs){
	std::strcpy(color,c);
}

std::ostream & operator<<(std::ostream &os, const lackDMA &rs){
	os << (baseDMA)rs;
	os << "Color: " << rs.color << std::endl;
	return os;
}

//hasDMA
hasDMA::hasDMA(const char *s, const char *l, int r) : baseDMA(l,r){
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}
hasDMA::hasDMA(const char *s,const baseDMA &rs) : baseDMA(rs){
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}
hasDMA::hasDMA(const hasDMA &rs) : baseDMA(rs){
	style = new char[std::strlen(rs.style) + 1];
	std::strcpy(style, rs.style);
}
hasDMA::~hasDMA(){
	delete[] style;
}
hasDMA & hasDMA::hasDMA::operator=(const hasDMA &rs){
	if(this == &rs)
		return *this;
	baseDMA::operator=(rs);
	delete[] style;
	style = new char[std::strlen(rs.style) + 1];
	std::strcpy(style,rs.style);
	return *this;
}

std::ostream & operator<<(std::ostream &os,const hasDMA &rs){
	os << (baseDMA) rs;
	os << "Style: " << rs.style << std::endl;
	return os;
}
