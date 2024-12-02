create table numeric_data(
    col1 integer,
    col2 integer
);

copy numeric_data (col1, col2)
from '/home/freedino/Desktop/coding thingy/advent_of_code_2024/day_1/input.txt'
with delimiter ' ';

select * from numeric_data;