#!/usr/bin/env bats

TEST=`cat <<EOF
0
1
2
3
4
5
6
7
8
9
10
11
EOF
`
TEST0=`cat <<EOF
0
1
2
3
4
5
6
7
8
9
10
11
EOF
`
TEST1=`cat <<EOF
EOF
`
TEST2=`cat <<EOF
this is my project0
EOF
`

TEST3=`cat <<EOF
0
1
2
3
4
5
6
EOF
`

TEST4=`cat <<EOF
9
10
11
EOF
`

TEST5=`cat <<EOF
7
EOF
`

TEST6=`cat <<EOF
3
4
5
6
7
EOF
`

TEST7=`cat <<EOF
        12
EOF
`
TEST8=`cat <<EOF
        12        26
EOF
`
@test "oucat" {
  result="$(./oucat myfile.txt)"
  [ "$result" = "$TEST" ]
}
@test "oucat1" {
  result="$(./oucat < myfile.txt)"
  [ "$result" = "$TEST" ]
}
@test "ouecho 1" {
  result1="$(./ouecho)"
  [ "$result1" = "$TEST1" ]
}
@test "ouecho 2" {
  result2="$(./ouecho this is my               project0)"
  [ "$result2" = "$TEST2" ]
}
@test "ouhead" {
result3="$(./ouhead -n 7 <  myfile.txt)"
  [ "$result3" = "$TEST3" ]
}
@test "outail" {
  result4="$(./outail -n 3 myfile.txt)"
  [ "$result4" = "$TEST4" ]
}
@test "ouseq 1" {
  result5="$(./ouseq 7 7)"
  [ "$result5" = "$TEST5" ]
}
@test "ouseq 2" {
  result6="$(./ouseq 3 7)"
  [ "$result6" = "$TEST6" ]
}
@test "ouwc" {
  result7="$(./ouwc -l myfile.txt)"
  [ "$result7" = "$TEST7" ]
}
@test "ouwc1" {
  result8="$(./ouwc -l -c myfile.txt)"
  [ "$result8" = "$TEST8" ]
}

