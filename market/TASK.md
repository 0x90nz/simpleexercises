# Market

You've been asked by a local variety market to write a program which will
translate orders that are easy for their computer system to read, but hard for
humans to read into orders which a human can easily read.

Their system stores items by their English name, in singular form. They've
kindly provided a comma-separated translation file to help you determine what
you should call an item if there are more than one of them.

## Task

Your task is to create a program which will transform those hard to read orders
into nicer ones. Each order is a single line of text and may contain a number of
items. You can assume that any provided item will be in the translation file.

You may make reasonable assumptions about input (e.g. maximum line length) as
you see fit. Aim to make your solution as general as possible within the
constraints of the language you are using.

There will be a number of lines containing orders. For each a response should be
printed across multiple lines as shown below. A line containing only the
sentinel character '#' marks the end of input, and your program should exit on
encountering this.

The format of a line is:

```text
name1=quantity1,name2=quantity2,name3=quantity3
```

Where `name` refers to the name of the item, e.g. "carrot" and quantity refers
to the number of that item included in the order.

The response to the program should be to list each item separately on a line.
The quantity should be first, as a decimal number and then the appropriate form
should follow it (i.e. plural if more than one is ordered, singular if only one
is ordered). After all the items are listed the total number of items should be
output. Items should be output in the same order they are encountered.

See "Sample Input" for example.

## Sample Input

### Case 1

Input:
```text
carrot=5,potato=2,fungus=1,vortex=2
#
```

Output:
```text
5 carrots
2 potatoes
1 fungus
2 vortices
total: 10 items
```

### Case 2

Input:
```text
potato=1
carrot=1,fungus=2
#
```

Output:
```text
1 potato
total: 1 item
1 carrot
2 fungi
total: 3 items
```
