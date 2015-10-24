import org.scalatest.FlatSpec
import org.scalatest.Matchers

class SolveSpec extends FlatSpec with Matchers{

  "Solve" should "return values given by problem description" in {  
    Solve.solve(1) should contain only (1)
 
    Solve.solve(2) should contain only (1,2)
    
    Solve.solve(3) should contain only (2,3,4)
    
    Solve.solve(4) should contain only (3,5,6,7)
    
    Solve.solve(5) should contain only (6,9,11,12,13)
    
    Solve.solve(6) should contain only (11, 18, 19, 20, 22, 25)
  }
  
  "Solve.containsEqualSubsets" should "work correctly" in {
    Solve.isBad(List(1)) should be (false)
    Solve.isBad(List(1,2)) should be (false)
    Solve.isBad(List(1,2,3)) should be (true)
    Solve.isBad(List(1,2,3,4)) should be (true)
    Solve.isBad(List(2,3,4)) should be (false)
    Solve.isBad(List(3,5,6,7)) should be (false)
    Solve.isBad(List(6,9,11,12,13)) should be (false)
    Solve.isBad(List(11, 18, 19, 20, 22, 25)) should be (false)
    Solve.isBad(List(11, 17, 20, 22, 23, 24)) should be (false)
  }
    
 
}
