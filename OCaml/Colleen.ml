let get_quine str =
	Printf.printf "%s%S" str str

(*
	this comment is outside a function
*)

let () =
	(*
		this comment is inside main
	*)
	get_quine "let get_quine str =\n\tPrintf.printf \"%s%S\" str str\n\n(*\n\tthis comment is outside a function\n*)\n\nlet () =\n\t(*\n\t\tthis comment is inside main\n\t*)\n\tget_quine "