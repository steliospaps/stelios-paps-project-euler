

import scala.math.BigInt
import scala.annotation.tailrec

object Solve extends App{
  def isPandigital(i:BigInt):Boolean = {
    val uniqueCount = i.toString().foldLeft(Set[Char]())((s,c)=>s+c).size
    uniqueCount == 9 && i.toString().length == 9 && i.toString().find { _ == '0' }.isEmpty
  }
  //http://stackoverflow.com/questions/9864497/generate-a-sequence-of-fibonacci-number-in-scala
  
  val fibs: Stream[(Int,BigInt)] = (0,BigInt(0)) #:: fibs.scanLeft((1,BigInt(1)))((n1,n2)=>(n1._1+1,n1._2+n2._2))
  @tailrec
  def first9(a:BigInt):BigInt ={
    if(a>=1000000000) first9(a/10)
    else a
  }
//  println(fibs.find(p => isPandigital(p._2%1000000000)).get)
//  println(fibs.find(p => isPandigital(first9(p._2))).get)
//  println(fibs.filter(p => isPandigital(p._2%1000000000))
//    .filter(p => isPandigital(first9(p._2))).head._1) //this runs out of memory      
  @tailrec
  def fibSearch(i:Int, prev:BigInt, cur:BigInt):Int = {
    //if(isPandigital(cur%1000000000)) i //first tail pandigital
    //if(isPandigital(first9(cur))) i //first head pandigital
    if(isPandigital(cur%1000000000) && isPandigital(first9(cur))) i
    else fibSearch(i+1, cur, cur+prev)
  }
  val found = fibSearch(1,0,1)
  println(found)
}