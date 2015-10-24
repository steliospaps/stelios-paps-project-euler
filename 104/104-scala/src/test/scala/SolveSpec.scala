import org.scalatest.FlatSpec
import org.scalatest.Matchers

class SolveSpec extends FlatSpec with Matchers{

  "isPandigital" should "work" in {  
    Solve.isPandigital(123456789) should be (true)
    Solve.isPandigital(23456789) should be (false)
    Solve.isPandigital(123457789) should be (false)
    Solve.isPandigital(123056789) should be (false)

  }    

  "fistNine" should "work" in {
    Solve.first9(1) should be (1)
    Solve.first9(1234567890) should be (123456789)
  }
}
