class Prime
{
  public:
    Prime(long aa,long bb)
    {
      a=aa;b=bb;
    }
    void get_answer();
  protected:
    long a,b,d,t;
    bool check(long p);
    bool M_R(long long base,long num);
    long paw_mod(long long bs,long power,long diver);
};
void Prime::get_answer()
{
  for(long i=a;i<=b;++i)
    if(check(i)) printf("%d\n",i);
}

bool Prime::check(long p)
{
  if(((p&1)!=0)&&(p%3!=0)&&(p>2)&&M_R(2,p)&&((p<=7)||M_R(7,p))&&((p<=61)||M_R(61,p))||(p==2)||(p==3)) return true;
  else return false;
}
bool Prime::M_R(long long base,long num)
{
  d=num-1;
  while((d&1)==0)
  {
    d=(d>>1);
  }
  if((paw_mod(base,d,num)==1)||(paw_mod(base,d,num)==num-1)) return true;
  else
  {
    t=(num-1)/2;
    while(d!=t)
    {
      d=(d<<1);
      if(paw_mod(base,d,num)==num-1) return true;
    }
    return false;
  }
}
long Prime::paw_mod(long long bs,long power,long diver)
{
  if(power==0) return(1);
  else if(power==1) return(bs);
  else if ((power&1)==0) return(paw_mod(bs*bs%diver,(power>>1),diver));
  else return(paw_mod(bs*bs%diver,power/2,diver)*bs%diver);
}
