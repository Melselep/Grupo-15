module Main where
import System.Environment (getArgs)   
import Data.List(sort)
import Bench (bench, list) 


main :: IO ()
main = do 
  args <- getArgs
  let wmIterations = read (head args) :: Int
  let iterations = read (last args) :: Int 
  bench "list#sort" sort list  wmIterations iterations
 