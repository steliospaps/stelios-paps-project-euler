

import scala.annotation.tailrec

object Solve extends App {
  def isBad(a:List[Int]): Boolean = {
  
  val bad = for(
              x <- a.permutations.toList;
              i <- 1 until x.length;
            (l,r) = x.splitAt(i);//looking for sets in r that have the same sum as l// or are >l with less items
            r1 <- r.permutations.toList;
            j <- 1 to r1.length;
            r2 = r1.take(j)
            if l.sum == r2.sum || (l.length>r2.length && l.sum < r2.sum)
            ) yield {
                  //println(a +":"+(l,r2))
                  (l,r2)              
            }
    !bad.isEmpty
  }
  def solve(n:Int):List[Int]={
    def search(soFar:List[Int],from:Int,tooBig:Int):Option[List[Int]] = {
      //println(n+" "+soFar+" "+from+" "+tooBig)
      if(soFar.length == 1) println(n+" "+soFar+" "+from+" "+tooBig)
      if(soFar.length == n) {
        if(isBad(soFar)) None
        else Some(soFar)
      } else {        
        val attemps = for(i<- Stream.range(from,tooBig)) yield {
            val bigest = if(soFar.isEmpty) tooBig else if(soFar.length==1) soFar.sum+i else soFar.take(2).sum
            //println(" "+i+" "+bigest)
            if(i<bigest) search(soFar:+i,i+1,bigest)
            else None
          }
        attemps.find(_.isDefined).getOrElse(None)
      }
    }
    search(Nil,1,20).get
  }
  def solve2(n:Int):List[List[Int]]={
    def search2(soFar:List[Int],from:Int,tooBig:Int):Stream[Option[List[Int]]] = {
      //println(n+" "+soFar+" "+from+" "+tooBig)
      if(soFar.length == 1) println(n+" "+soFar+" "+from+" "+tooBig)
      if(soFar.length == n) {
        if(isBad(soFar)) Stream.Empty
        else Stream(Some(soFar))
      } else {        
        val attemps = for(i<- Stream.range(from,tooBig)) yield {
            val bigest = if(soFar.isEmpty) tooBig else if(soFar.length==1) soFar.sum+i else soFar.take(2).sum
            //println(" "+i+" "+bigest)
            if(i<bigest) search2(soFar:+i,i+1,bigest)
            else Stream.empty
          }
        attemps.flatten
      }
    }
    search2(Nil,19,30).filter({_.isDefined}).map { _.get}.toList
  }
  println(solve2(7).foldLeft(List(Int.MaxValue))((a,b)=>if(a.sum<b.sum) a else b))
}