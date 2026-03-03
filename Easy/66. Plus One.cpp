class Solution(object):
    def plusOne(self, digits):
        l=len(digits)
        for i in range(l):
            if digits[l-i-1] == 9 :
                digits[l-i-1] = 0
                if i== l-1 :
                    digits.insert(0,1)
            else :
                digits[l-i-1] += 1
                break
        return digits
        
/* start from last number 
, if number is 9 , change it to 0 and check next number 
, if next number is also 9 , change it to 0 and check next number until you find a number which is not 9
, then add 1 to that number and break the loop . If all numbers are 9 then add 1 at the beginning of the list . */