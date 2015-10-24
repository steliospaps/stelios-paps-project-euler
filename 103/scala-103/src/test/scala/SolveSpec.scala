import org.scalatest.FlatSpec

class SolveSpec extends FlatSpec {

  "disjoint subsets" should "not be equal" in {
    assert(Set.empty.size == 0)
  }

  it should "produce NoSuchElementException when head is invoked" in {
    intercept[NoSuchElementException] {
      Set.empty.head
    }
  }
}
