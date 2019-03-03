library(stringr); library(stringi)

lcoeff=0.04
letter.read <- function(filename)
{
	readF<-scan(file=filename,what=character(0) )
}

count.char<- function(str)
{
	ind =1
	charlength<-length(charset)
	setFm=numeric(charlength)
	source_Fall=paste(str, collapse=' ')
	source_Fall_without_spaces=paste(gsub(" ", "",source_Fall))
	 while (ind<=charlength)
	 {
		 resultF=str_count(source_Fall_without_spaces, charset[ind])
		 setFm[ind]=as.double(resultF/charlength)
		 ind=ind+1
		 }
		 setFm
	 }

correlate.letter<-function(count1,count2)
{
	corr=cor(count1,count2)
	print (corr)
#	Student_test=t.test(count1,count2)
#	print (Student_test)
	ARG=log(corr)/(-lcoeff*corr)
	SW_TIME=sqrt(ARG)
	leshiner_time =5*(1-log(corr))/(1-log(1-corr))
	print (paste0('SW_TIME = ', SW_TIME))
	print (paste0('leshiner_time = ', leshiner_time))
	
}

charset=letter.read("charset")
str1=letter.read("russian")
str2=letter.read("polish")
str3=letter.read("serbian")
str4=letter.read("oldchurch")
str5=letter.read("slovak")
str6=letter.read("slovenian")
str7=letter.read("makedonian")
str8=letter.read("belarusian")
str9=letter.read("english")
str10=letter.read("latin")
str11=letter.read("breton")

strd1=count.char(str1)
strd2=count.char(str2)
strd3=count.char(str3)
strd4=count.char(str4)
strd5=count.char(str5)
strd6=count.char(str6)
strd7=count.char(str7)
strd8=count.char(str8)
strd9=count.char(str9)
strd10=count.char(str10)
strd11=count.char(str11)

print(" Корреляция языков русского и польского")
correlate.letter(strd1, strd2)
print(" Корреляция языков русского и сербского")
correlate.letter(strd1, strd3)
print(" Корреляция языков русского и цся")
correlate.letter(strd1, strd4)
print(" Корреляция языков русского и словакского")
correlate.letter(strd1, strd5)
print(" Корреляция языков русского и словенского")
correlate.letter(strd1, strd6)
print(" Корреляция языков русского и македонского")
correlate.letter(strd1, strd7)
print(" Корреляция языков русского и беларуского")
correlate.letter(strd1, strd8)
print(" Корреляция языков русского и английского")
correlate.letter(strd1, strd9)
print(" Корреляция языков русского и латинского")
correlate.letter(strd1, strd10)
print(" Корреляция языков русского и бретонского")
correlate.letter(strd1, strd11)

boxplot(strd1,strd2,strd3,strd4,strd5,strd6,strd7,strd8, strd9, strd10, strd11)
#cplot(strd1,strd2,strd3,strd4,strd5,strd6,strd7,strd8 )
