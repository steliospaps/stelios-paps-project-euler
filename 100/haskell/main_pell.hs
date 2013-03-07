approx_sqr_8=([2] ++ (cycle [1, 4]))
    
box_next p1 p2 x = p2*x + p1
        
box p1 p2 l = [c] ++ (box p2 c (tail l)) where c=box_next p1 p2 (head l)
                                                   
b1 = zip (box 0 1 approx_sqr_8) (box 1 0 approx_sqr_8)
                                                   
box_next_pair p1 p2 x = (box_next (fst p1) (fst p2) x,box_next (snd p1) (snd p2) x)

box2 p1 p2 l = [c] ++ (box2 p2 c (tail l)) where c=box_next_pair p1 p2 (head l)
                                                     
desc (p1,p2) l  | length l == 0 = (p1, p2) | otherwise = desc (p2, (box_next p1 p2 (head l))) (tail l) 

d (a,b) l = [box_next a b (head l)] ++ d (desc (a,b) l) l 

box2_s (s1,s2) h r = d (s2,s) r  where s = box_next s1 s2 h   

foo = zip (box2_s (0,1) 2 [1,4]) (box2_s (1,0) 2 [1,4])



sol = [ ((red p),(snd p)) | p <- foo , ((red p)+(snd p))>1000000000000] where red(x,y)=(1+2*y + x) `div` 2

main=print (head sol)

--756872327473,
--313506783024
                                                                              