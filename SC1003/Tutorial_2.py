####################
#  Discussion 1
# value = 6
# if value % 2 == 0:
#     print("first", value)
# elif value % 3 == 0:
#     print("second", value)

# while value <= 9:
#     value = value + 1
#     if value == 8:
#         continue
#     else:
#         pass
#     print("third", value)
# else:
#     print("fourth", value)

# print("fifth", value)

# Output is:
# first 6
# third 7
# third 9
# third 10
# fourth 10
# fifth 10

#######################
# Discussion 2:
# Errors: Never declare initial count, and count is put outside of if statement,
# so will add even if no 'a'. Print is also within for loop, so will execute every
# time instead of at the end. Never put end condition.

# count = 0  # Error 1 - count not declared

# while True:
#     str = input("enter a string: ")
#     if str == '####':  # Error 4 - no breaking out of while
#         break
#     else:
#         for letter in str:
#             if letter == 'a':
#                 count += 1  # Error 2 - count in wrong indentation
#                 break

# print(count, "strings with letter 'a'")  # Error 3 - print in while loop

#######################
# Discussion 3: FizzBuzz

# for count in range(1, 21):
#     print('FizzBuzz') if (count % 5 == 0) and (count % 3 == 0) else print('Fizz') if (
#         count % 3 == 0) else print('Buzz') if (count % 5 == 0) else print(count)

# for count in range(1, 21):
#     if count % 3 == 0:
#         if count % 5 == 0:
#             print('FizzBuzz')
#         else:
#             print('Fizz')
#     elif count % 5 == 0:
#         print('Buzz')
#     else:
#         print(count)

#######################
# Discussion 4: Pyramids

# for count in range(1, int(input("Please enter pattern width: "))*2):
#     print('*'*min(count, 10-count))

# maxwidth = int(input("Please enter pattern width: "))

# for height in range(0, maxwidth * 2 - 1):
#     if height < 4:
#         rowwidth = height + 1
#     else:
#         rowwidth = maxwidth * 2 - 1 - height
#     for width in range(0, rowwidth):
#         print('*', end="")
#     print("")
