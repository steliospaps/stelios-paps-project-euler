package euler.p101

import scala.math.BigDecimal
import scala.annotation.tailrec

object Solve extends App{
	println("Hi!")
  val p = new Poly(List(0,0,0,1))
  val points = for( i <- 0 to 2) yield (BigDecimal(i),p(i))
  println(points)
  val pf = new PolyFit(points)
  val estimate = for( i <- 0 to 3) yield (BigDecimal(i),pf(i))
  println(estimate)
  
}
/**
 * @author stelios
 */
class Poly(vals:List[BigDecimal]) {
  def apply(x:BigDecimal):BigDecimal = {
    @tailrec
    def calc(sum:BigDecimal,v:BigDecimal,rest:Seq[BigDecimal]):BigDecimal={
      rest match {
        case Nil => sum
        case c :: tail => calc(sum+c*v,v*x,tail)
      }
    }
    calc(0,1,vals)
  }
}

class PolyFit(points : Seq[(BigDecimal,BigDecimal)]){
  def apply(x:BigDecimal):BigDecimal = {
    def arg(xi:BigDecimal):BigDecimal = {
      val args = for(p <- points 
          if p._1 != xi) yield {(x - p._1)/(xi-p._1)}
      args.reduce((a,b)=>a*b)
    }
    val components = for(p <- points) yield {
      //see https://en.wikipedia.org/wiki/Polynomial_interpolation
      arg(p._1)*p._2
    }
    components.sum
  }
}
