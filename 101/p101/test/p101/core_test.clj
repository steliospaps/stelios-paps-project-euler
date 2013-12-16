(ns p101.core-test
  (:require [clojure.test :refer :all]
            [p101.core :refer :all]))

(deftest gaussian-simple
  (testing ""
    (is (= '(1 2 3) (gaussian-elimination
                    '((1 1 1 6)
                     (2 1 1 7)
                     (1 2 3 14)
                     ))))))

(deftest eliminate
  (testing "reorder"
    (is (= '((2 0 0)
            (1 0 0)
            (0 0 0))
           (reorder 0 '((1 0 0)
              (0 0 0)
              (2 0 0)
              )
                    )))))

(deftest eliminate
  (testing "reorder2"
    (is (= '((2 1 0)
            (1 7 0)
            (0 1 0))
           (reorder 1 '((2 1 0)
              (0 1 0)
              (1 7 0)
              )
                    )))))
