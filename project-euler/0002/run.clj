
;; fibs from stack over flow
(def fibs 
    (map first 
         (iterate (fn [[ a, b       ]]  
                      [ b, (+ a b) ]) 
                  [0, 1])))     

;; fib-seq from stack over flow. COOL!
(def fib-seq (lazy-cat [0 1] (map + fib-seq (rest fib-seq))))

(prn (reduce + (filter even? (take-while #(< % 4000000) fib-seq))))

