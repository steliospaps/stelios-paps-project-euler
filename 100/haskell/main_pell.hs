box_next p1 p2 x = p2*x + p1
        
desc (p1,p2) l  | length l == 0 = (p1, p2) | otherwise = desc (p2, (box_next p1 p2 (head l))) (tail l) 

d (a,b) l = [box_next a b (head l)] ++ d (desc (a,b) l) l 
--device to calculate periodic rcontinued fraction 0,1 enum , 1,0 denom
box2_s (s1,s2) h r = d (s2,s) r  where s = box_next s1 s2 h   

-- (n,y) where n^2-8y^2=1 Note: sqrt(8) == periodic continued fraction 2,1,4,1,4,1,4...
det_roots = zip (box2_s (0,1) 2 [1,4]) (box2_s (1,0) 2 [1,4])

--return red,blue combinations where (red-1)(red)/((red+blue)(red+blue-1)) == 2
solutions = [ ((red p),(snd p)) | p <- det_roots , ((red p)+(snd p))>1000000000000] where red(x,y)=(1+2*y + x) `div` 2

main=print (head solutions)

--756872327473,
--313506783024
                                                                              