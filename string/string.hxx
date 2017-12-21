#ifndef _LYF_STRING_
#define _LYF_STRING_
#include<string>
#include<regex>
#include<vector>

std::string replpaceAll(std::string src, std::string rp, std::string by)
{
	size_t pos = src.find(rp);
	while (pos != std::string::npos)
	{
		src = src.replace(pos, rp.length(), by);
		pos = src.find(rp, pos + by.length());
	}
	return src;
}

std::string trim(std::string src,std::string dec)
{
	size_t pos = src.find_first_not_of(dec);
	if (pos != std::string::npos)
		src = src.substr(pos);
	pos = src.find_last_not_of(dec);
	if (pos != std::string::npos)
		src = src.substr(0, pos+1);
	return src;
}

std::vector<std::string> split(std::string src,std::string dec)
{
	std::vector<std::string> res;
	src = trim(src, dec);
	size_t pos = src.find(dec);
	while ( pos != std::string::npos)
	{
		res.push_back(src.substr(0, pos));
		src = src.substr(pos+1);
		pos = src.find(dec);
	}
	res.push_back(src);
	return res;
}

std::string replpaceAllReg(std::string src, std::string rp, std::string by)
{
	std::regex rg(rp);
	return std::regex_replace(src, rg, by);
}

std::vector<std::string> splitReg(std::string src, std::string dec)
{
	std::vector<std::string> res;
	std::regex rg(dec);
	std::sregex_token_iterator sEnd, sIter(src.begin(), src.end(), rg,-1);
	for (; sIter != sEnd; ++sIter) {
		if(!sIter->str().empty())
			res.push_back(sIter->str());
	}
	return res;
}

#endif  // _LYF_STRING_