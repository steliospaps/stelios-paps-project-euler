
main =  print res 
        where res = head   [(a,b) | b<-[10^6..], a <-[f (b*(b-1)) 1 b ] , a>0 ]

f target min max = 
  if min+1>=max 
  then -1 
  else if mid2>target 
       then f target min mid 
       else if mid2<target 
            then f target mid max else mid 
  where mid = div (max+min) 2
        mid2 = 2*mid*(mid-1)