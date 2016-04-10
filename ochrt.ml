open Printf;;
open Char;;

let f_in =
  try
    open_in_bin Sys.argv.(1)
  with Invalid_argument _ -> stdin;;

let print_binary num = 
 for i = 7 downto 0 do
    print_char (if ((num lsr i) mod 2) = 0 then '0' else '1')
 done;;

print_endline "indx int binary   hex  char";

let byte_count = ref 0 in
try
  while true do
    let byte = input_byte f_in in
      (*print_int !byte_count;*)
      Printf.printf "%-4d" !byte_count;
      byte_count := succ !byte_count;
      print_char ' ';
      Printf.printf "%-3d " byte;
      print_binary byte;
      print_char ' ';
      Printf.printf "0x%02X " byte;
      print_string (escaped (chr byte));
      print_endline "";
  done
with End_of_file ->
  close_in f_in;;
