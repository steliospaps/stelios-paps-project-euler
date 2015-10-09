package euler.p102

import scala.io.Source
object Solve extends App {
  val s= Source.fromFile("../p102_triangles.txt").
    getLines().map(
        _.split(",").
        map(_.toDouble).
        grouped(2).
        map(a=>(a(0),a(1)))
        .grouped(3).map(a=>new Triangle(a(0),a(1),a(2)))
        ).flatten.count(x => x.contains((0,0)))
  println(s)
  /*
   * val f=s.next
   
  println(f)
  println(f.contains((0,0)))
  val f2=s.next
  println(f2)
  println(f2.contains((0,0)))
  */
//  println(new Triangle((-1,-1),(1,0),(0,1)).contains((0,0)))
}

class Triangle(a:(Double,Double),b:(Double,Double),c:(Double,Double)){
  val v1=(b._1-a._1,b._2-a._2)
  val v2=(c._1-a._1,c._2-a._2)
  private def det(u:(Double,Double),v:(Double,Double)):Double={ u._1*v._2-u._2*v._1 } 
  def contains(v:(Double,Double)):Boolean = {
    //see http://mathworld.wolfram.com/TriangleInterior.html
    //val v:(Double,Double)=(p._1-a._1,p._2-a._2)
    val aa:Double=(det(v,v2)-det(a,v2))/det(v1,v2)
    val bb=(det(a,v1)-det(v,v1))/det(v1,v2)
    println(v1)
    println(v2)
    println(a)
    println(aa)
    println(bb)
    aa>=0 && bb>=0 && (aa+bb)<=1.0
  }
  override def toString():String = "["+a.toString()+","+b.toString()+","+c.toString()+"]"
}
