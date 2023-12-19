regex wordRegex("\\b[A-Za-z]\\b");
auto wordBegin=sregex_iterator(line.begin(),line.end(),wordRegex);
auto wordEnd=sregex_iterator();
for(sregex_iterator it=wordBegin;it!=wordEnd;it++)
{
      smatch match=*it;
      string word=match.str();
}      
