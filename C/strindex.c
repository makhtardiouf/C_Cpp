/*
$Id: strindex.c 5 2007-03-31 15:04:06Z Makhtar $
Get the index of a string
*/

int strindex(char s[], char t[]) {
  int i, j, k;

  /* move index from the beginning till
     the end of each line  */
  for (i = 0; s[i] != '\0'; i++) {
    /* move index from the beginning of the target  */
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      continue;

    if (k > 0 && t[k] == '\0')
      return i;
  }
  /* complain if we get here */
  return (-1);
}
