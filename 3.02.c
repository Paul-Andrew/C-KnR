
/*
* takes a char string t and removes escape characters 
* to be replaced by visible representations \n,\t,\b, etc.
* Places new string into s.
*/

int escape(char **s,char **t)
{
  if (sizeof(t) == sizeof(s) && sizeof(t[0]) == sizeof(s[0])){
    int i,l = (sizeof(t)/sizeof(t[0]));
    for (i=0;i < l;i++){
      switch (t[i]){
	case '\a':
	  s[i] = "\\a";
	case '\b':
	  s[i] = "\\b";
	case '\f':
	  s[i] = "\\f";
	case '\n':
	  s[i] = "\\n";
	case '\r':
	  s[i] = "\\r";
	case '\t':
	  s[i] = "\\t";
	case '\v':
	  s[i] = "\\v"; 
	case '\'':
	  s[i] = "\\'";
	case '\"':
	  s[i] = "\\"";
	default:
	  s[i] = t[i];
      }
    }
    return 0;
  }
  return -1;
}
