(ns p101.core
  (:gen-class))

(defn reorder [cr m] (concat (take cr m) (reverse (sort-by #(nth % cr) (drop cr m)))))

(defn gaussian-elimination [m] '())

(defn -main
  "I don't do a whole lot ... yet."
  [& args]
  (println "Hello, World!"))
