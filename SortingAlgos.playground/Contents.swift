//: Playground - noun: a place where people can play
import Foundation

/*let V: Int = readLn()
let N: Int = readLn()
var numbers = [Int](count:N, repeatedValue: 0)
numbers = readLn()*/

let N: Int = 20
let V:Int = 10
var numbers = [Int](count:N, repeatedValue: 0)
numbers = [1,2,3,4,5,6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]


public func getLine() -> String {
    var buf = String()
    var c = getchar()
    // 10 is ascii code for newline
    while c != EOF && c != 10 {
        buf.append(UnicodeScalar(UInt32(c)))
        c = getchar()
    }
    return buf
}

public func readLn() -> Int {
    return Int(getLine())!
}

public func readLn() -> [String] {
    return getLine().componentsSeparatedByCharactersInSet(NSCharacterSet.whitespaceCharacterSet())
}

public func readLn() -> [Int] {
    let words: [String] = readLn()
    return words.map { Int($0)! }
}

var startIndex:Int = numbers.startIndex
var endIndex:Int = numbers.endIndex

var midPoint:Int = (startIndex + endIndex) / 2


func searchValue<T: Comparable>(var numbers: [T],V:T) -> Int {
    
    if(numbers[midPoint] == V) {
        return midPoint
    }
    
    if(numbers[midPoint] > V){
        endIndex = midPoint
        midPoint = (startIndex + midPoint) / 2
        return searchValue(numbers,V: V)
    }else {
        startIndex = midPoint
        midPoint = (endIndex + midPoint) / 2
        return searchValue(numbers,V: V)
    }
    
}

func insertionSort<T: Comparable>(var input: [T],size: Int) -> [T] {
    var value:T,j:Int
    for index in 2..<size {
        value = input[index]
        j = index
        while(input[index-1] > value && j >= 1){
            input[j] = input[j-1]
            j--
        }
        input[j] = value
    }
    
    return input
}

func bubbleSort<T: Comparable>(var input: [T],size: Int) -> [T] {
    var end = size - 1
    var swapped:Bool = true

    while(swapped) {
        swapped = false // no more swaps, sorted
        if end == 0 {
            break
        }

        for index in 0..<end {
            if input[index] > input[index + 1] {
                swapped = true
                swap(&input[index], &input[index+1])
            }
        }
        
        end--
    }
    return input
}

func selectionSort<T: Comparable>(var input: [T],size: Int) -> [T] {
    var minIndex:Int
    
    for index in 0..<size-1 {
        minIndex = index
        for j in index+1..<size {
            if input[j] < input[minIndex] {
                minIndex = j
            }
        }
        swap(&input[minIndex], &input[index])
    }
    return input
}

func merge<T: Comparable>(var leftArr:[T],var rightArr:[T], mergedArr: [T]) -> [T] {
    
    if leftArr.isEmpty || rightArr.isEmpty {
        return mergedArr + rightArr + leftArr
    }
    
    if leftArr[0] > rightArr[0] {
        return merge(leftArr, rightArr: Array(rightArr[1..<rightArr.count]), mergedArr: mergedArr + [rightArr[0]])
    }
    else {
        return merge(Array(leftArr[1..<leftArr.count]), rightArr: rightArr, mergedArr: mergedArr + [leftArr[0]])
    }
    
}

func mergeSort<T: Comparable>(a:[T]) -> [T] {
    
    return a.count < 2 ? a :
        merge(mergeSort(Array(a[0..<a.count / 2])),
            rightArr: mergeSort(Array(a[a.count / 2..<a.count])),mergedArr: [])
}

print(searchValue(numbers,V:V));
print(insertionSort(numbers,size:N));
print(bubbleSort(numbers,size:N));
print(selectionSort(numbers,size:N));
print(mergeSort(numbers));

