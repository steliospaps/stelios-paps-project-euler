import Control.Parallel.Strategies
import Control.Parallel
import System.Environment
import Text.Printf

(^!) :: Num a => a -> Int -> a
(^!) x n = x^n
squareRoot :: Integer -> Integer
squareRoot 0 = 0
squareRoot 1 = 1
squareRoot n =
   let twopows = iterate (^!2) 2
       (lowerRoot, lowerN) =
          last $ takeWhile ((n>=) . snd) $ zip (1:twopows) twopows
       newtonStep x = div (x + div n x) 2
       iters = iterate newtonStep (squareRoot (div n lowerN) * lowerRoot)
       isRoot r  =  r^!2 <= n && n < (r+1)^!2
   in  head $ dropWhile (not . isRoot) iters
       
       
is_perfect_square n =
  let binary_search low high =
        let mid = low + ((high-low) `div` 2)
            midSquare = mid * mid
        in
        if low > high then False
        else if n == midSquare then True
        else if n < midSquare then binary_search low (mid - 1)
        else binary_search (mid + 1) high
  in binary_search 1 n

is_integral_area side diff 
   | c `mod` 4 == 0 = is_perfect_square(b)
   | c `mod` 2 == 0 = b `mod` 4 == 0 && is_perfect_square(b `div` 4)
   | otherwise = b `mod` 16 == 0 && is_perfect_square(b `div` 16)
    where c=side+diff
          b=(side-diff)*(3*side+diff)
  

bigSide n =  [3*x + 1|x<-[1..n], is_integral_area x 1] 
smallSide n=  [3*x-1 |x<-[2..n], is_integral_area x (-1)] 

comp n =
  small `par` (big `pseq` small + big)
    where small = sum(smallSide n) 
          big = sum(bigSide n) 
                
bigSideR n sum1
  | n==0 = return sum1
  | otherwise = 
    if is_integral_area n 1 then
      bigSideR (n-1) (3*n+1+sum1) 
    else 
      bigSideR (n-1) sum1
smallSideR n sum
  | n==1 = return sum
  | otherwise = 
    if is_integral_area n (-1) then
      smallSideR (n-1) (3*n-1+sum) 
    else 
      smallSideR (n-1) sum

comp2 n =
  small `par` (big `pseq` small + big)
    where small = smallSideR( n 0) 
          big = bigSideR( n 0) 
      
main = 
  do
    [d] <- map read `fmap` getArgs
    print (comp2 d)