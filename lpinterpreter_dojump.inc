{
	Author: Niels A.D
	Project: Lape (http://code.google.com/p/la-pe/)
	License: GNU Lesser GPL (http://www.gnu.org/licenses/lgpl.html)

	All the jump related handling functions.
}
{%MainUnit lpinterpreter.pas}

procedure DoJmp; {$IFDEF FPC}{$IFDEF Lape_Inline}inline;{$ENDIF}{$ENDIF}
begin
  JumpTo(PUInt32(PtrUInt(Code) + ocSize)^);
end;

procedure DoJmpR; {$IFDEF FPC}{$IFDEF Lape_Inline}inline;{$ENDIF}{$ENDIF}
begin
  JumpToRelative(PInt32(PtrUInt(Code) + ocSize)^);
end;

//jump if
(*
procedure DoJmpIf8_Stk; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  if (PUInt8(@Stack[StackPos - SizeOf(UInt8)])^ <> 0) then
    JumpTo(PUInt32(PtrUInt(Code) + ocSize)^)
  else
    Inc(Code, SizeOf(UInt32) + ocSize);
  Dec(StackPos, SizeOf(UInt8));
end;

procedure DoJmpIf16_Stk; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  if (PUInt16(@Stack[StackPos - SizeOf(UInt16)])^ <> 0) then
    JumpTo(PUInt32(PtrUInt(Code) + ocSize)^)
  else
    Inc(Code, SizeOf(UInt32) + ocSize);
  Dec(StackPos, SizeOf(UInt16));
end;

procedure DoJmpIf32_Stk; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  if (PUInt32(@Stack[StackPos - SizeOf(UInt32)])^ <> 0) then
    JumpTo(PUInt32(PtrUInt(Code) + ocSize)^)
  else
    Inc(Code, SizeOf(UInt32) + ocSize);
  Dec(StackPos, SizeOf(UInt32));
end;

procedure DoJmpIf64_Stk; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  if (PUInt64(@Stack[StackPos - SizeOf(UInt64)])^ <> 0) then
    JumpTo(PUInt32(PtrUInt(Code) + ocSize)^)
  else
    Inc(Code, SizeOf(UInt32) + ocSize);
  Dec(StackPos, SizeOf(UInt64));
end;

procedure DoJmpIf8_Var; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_Jmp_Var(PtrUInt(Code) + ocSize)^ do
    if (PUInt8(@VarStack[VarStackPos + VarStackOffset])^ <> 0) then
      JumpTo(Target)
    else
      Inc(Code, SizeOf(TOC_Jmp_Var) + ocSize);
end;

procedure DoJmpIf16_Var; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_Jmp_Var(PtrUInt(Code) + ocSize)^ do
    if (PUInt16(@VarStack[VarStackPos + VarStackOffset])^ <> 0) then
      JumpTo(Target)
    else
      Inc(Code, SizeOf(TOC_Jmp_Var) + ocSize);
end;

procedure DoJmpIf32_Var; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_Jmp_Var(PtrUInt(Code) + ocSize)^ do
    if (PUInt32(@VarStack[VarStackPos + VarStackOffset])^ <> 0) then
      JumpTo(Target)
    else
      Inc(Code, SizeOf(TOC_Jmp_Var) + ocSize);
end;

procedure DoJmpIf64_Var; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_Jmp_Var(PtrUInt(Code) + ocSize)^ do
    if (PUInt64(@VarStack[VarStackPos + VarStackOffset])^ <> 0) then
      JumpTo(Target)
    else
      Inc(Code, SizeOf(TOC_Jmp_Var) + ocSize);
end;

procedure DoJmpIf8_Ptr; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_Jmp_Ptr(PtrUInt(Code) + ocSize)^ do
    if (PUInt8(Ptr)^ <> 0) then
      JumpTo(Target)
    else
      Inc(Code, SizeOf(TOC_Jmp_Ptr) + ocSize);
end;

procedure DoJmpIf16_Ptr; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_Jmp_Ptr(PtrUInt(Code) + ocSize)^ do
    if (PUInt16(Ptr)^ <> 0) then
      JumpTo(Target)
    else
      Inc(Code, SizeOf(TOC_Jmp_Ptr) + ocSize);
end;

procedure DoJmpIf32_Ptr; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_Jmp_Ptr(PtrUInt(Code) + ocSize)^ do
    if (PUInt32(Ptr)^ <> 0) then
      JumpTo(Target)
    else
      Inc(Code, SizeOf(TOC_Jmp_Ptr) + ocSize);
end;

procedure DoJmpIf64_Ptr; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_Jmp_Ptr(PtrUInt(Code) + ocSize)^ do
    if (PUInt64(Ptr)^ <> 0) then
      JumpTo(Target)
    else
      Inc(Code, SizeOf(TOC_Jmp_Ptr) + ocSize);
end;

procedure DoJmpIf8_PStk; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  if (PUInt8(PPointer(@Stack[StackPos - SizeOf(Pointer)])^)^ <> 0) then
    JumpTo(PUInt32(PtrUInt(Code) + ocSize)^)
  else
    Inc(Code, SizeOf(UInt32) + ocSize);
  Dec(StackPos, SizeOf(UInt8));
end;

procedure DoJmpIf16_PStk; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  if (PUInt16(PPointer(@Stack[StackPos - SizeOf(Pointer)])^)^ <> 0) then
    JumpTo(PUInt32(PtrUInt(Code) + ocSize)^)
  else
    Inc(Code, SizeOf(UInt32) + ocSize);
  Dec(StackPos, SizeOf(UInt16));
end;

procedure DoJmpIf32_PStk; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  if (PUInt32(PPointer(@Stack[StackPos - SizeOf(Pointer)])^)^ <> 0) then
    JumpTo(PUInt32(PtrUInt(Code) + ocSize)^)
  else
    Inc(Code, SizeOf(UInt32) + ocSize);
  Dec(StackPos, SizeOf(UInt32));
end;

procedure DoJmpIf64_PStk; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  if (PUInt64(PPointer(@Stack[StackPos - SizeOf(Pointer)])^)^ <> 0) then
    JumpTo(PUInt32(PtrUInt(Code) + ocSize)^)
  else
    Inc(Code, SizeOf(UInt32) + ocSize);
  Dec(StackPos, SizeOf(UInt64));
end;

procedure DoJmpIf8_PVar; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_Jmp_PVar(PtrUInt(Code) + ocSize)^ do
    if (PUInt8(PtrUInt(PPointer(@VarStack[VarStackPos + VarStackOffset])^) + PointerOffset)^ <> 0) then
      JumpTo(Target)
    else
      Inc(Code, SizeOf(TOC_Jmp_PVar) + ocSize);
end;

procedure DoJmpIf16_PVar; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_Jmp_PVar(PtrUInt(Code) + ocSize)^ do
    if (PUInt16(PtrUInt(PPointer(@VarStack[VarStackPos + VarStackOffset])^) + PointerOffset)^ <> 0) then
      JumpTo(Target)
    else
      Inc(Code, SizeOf(TOC_Jmp_PVar) + ocSize);
end;

procedure DoJmpIf32_PVar; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_Jmp_PVar(PtrUInt(Code) + ocSize)^ do
    if (PUInt32(PtrUInt(PPointer(@VarStack[VarStackPos + VarStackOffset])^) + PointerOffset)^ <> 0) then
      JumpTo(Target)
    else
      Inc(Code, SizeOf(TOC_Jmp_PVar) + ocSize);
end;

procedure DoJmpIf64_PVar; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_Jmp_PVar(PtrUInt(Code) + ocSize)^ do
    if (PUInt64(PtrUInt(PPointer(@VarStack[VarStackPos + VarStackOffset])^) + PointerOffset)^ <> 0) then
      JumpTo(Target);
    else
      Inc(Code, SizeOf(TOC_Jmp_PVar) + ocSize);
end;
*)

//jump relative if
procedure DoJmpRIf8_Stk; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  if (PUInt8(@Stack[StackPos - SizeOf(UInt8)])^ <> 0) then
    JumpToRelative(PInt32(PtrUInt(Code) + ocSize)^)
  else
    Inc(Code, SizeOf(Int32) + ocSize);
  Dec(StackPos, SizeOf(UInt8));
end;

procedure DoJmpRIf16_Stk; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  if (PUInt16(@Stack[StackPos - SizeOf(UInt16)])^ <> 0) then
    JumpToRelative(PInt32(PtrUInt(Code) + ocSize)^)
  else
    Inc(Code, SizeOf(Int32) + ocSize);
  Dec(StackPos, SizeOf(UInt16));
end;

procedure DoJmpRIf32_Stk; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  if (PUInt32(@Stack[StackPos - SizeOf(UInt32)])^ <> 0) then
    JumpToRelative(PInt32(PtrUInt(Code) + ocSize)^)
  else
    Inc(Code, SizeOf(Int32) + ocSize);
  Dec(StackPos, SizeOf(UInt32));
end;

procedure DoJmpRIf64_Stk; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  if (PUInt64(@Stack[StackPos - SizeOf(UInt64)])^ <> 0) then
    JumpToRelative(PInt32(PtrUInt(Code) + ocSize)^)
  else
    Inc(Code, SizeOf(Int32) + ocSize);
  Dec(StackPos, SizeOf(UInt64));
end;

procedure DoJmpRIf8_Var; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_JmpR_Var(PtrUInt(Code) + ocSize)^ do
    if (PUInt8(@VarStack[VarStackPos + VarStackOffset])^ <> 0) then
      JumpToRelative(Offset)
    else
      Inc(Code, SizeOf(TOC_JmpR_Var) + ocSize);
end;

procedure DoJmpRIf16_Var; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_JmpR_Var(PtrUInt(Code) + ocSize)^ do
    if (PUInt16(@VarStack[VarStackPos + VarStackOffset])^ <> 0) then
      JumpToRelative(Offset)
    else
      Inc(Code, SizeOf(TOC_JmpR_Var) + ocSize);
end;

procedure DoJmpRIf32_Var; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_JmpR_Var(PtrUInt(Code) + ocSize)^ do
    if (PUInt32(@VarStack[VarStackPos + VarStackOffset])^ <> 0) then
      JumpToRelative(Offset)
    else
      Inc(Code, SizeOf(TOC_JmpR_Var) + ocSize);
end;

procedure DoJmpRIf64_Var; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_JmpR_Var(PtrUInt(Code) + ocSize)^ do
    if (PUInt64(@VarStack[VarStackPos + VarStackOffset])^ <> 0) then
      JumpToRelative(Offset)
    else
      Inc(Code, SizeOf(TOC_JmpR_Var) + ocSize);
end;

procedure DoJmpRIf8_Ptr; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_JmpR_Ptr(PtrUInt(Code) + ocSize)^ do
    if (PUInt8(Ptr)^ <> 0) then
      JumpToRelative(Offset)
    else
      Inc(Code, SizeOf(TOC_JmpR_Ptr) + ocSize);
end;

procedure DoJmpRIf16_Ptr; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_JmpR_Ptr(PtrUInt(Code) + ocSize)^ do
    if (PUInt16(Ptr)^ <> 0) then
      JumpToRelative(Offset)
    else
      Inc(Code, SizeOf(TOC_JmpR_Ptr) + ocSize);
end;

procedure DoJmpRIf32_Ptr; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_JmpR_Ptr(PtrUInt(Code) + ocSize)^ do
    if (PUInt32(Ptr)^ <> 0) then
      JumpToRelative(Offset)
    else
      Inc(Code, SizeOf(TOC_JmpR_Ptr) + ocSize);
end;

procedure DoJmpRIf64_Ptr; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_JmpR_Ptr(PtrUInt(Code) + ocSize)^ do
    if (PUInt64(Ptr)^ <> 0) then
      JumpToRelative(Offset)
    else
      Inc(Code, SizeOf(TOC_JmpR_Ptr) + ocSize);
end;

procedure DoJmpRIf8_PStk; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  if (PUInt8(PPointer(@Stack[StackPos - SizeOf(Pointer)])^)^ <> 0) then
    JumpToRelative(PInt32(PtrUInt(Code) + ocSize)^)
  else
    Inc(Code, SizeOf(UInt32) + ocSize);
  Dec(StackPos, SizeOf(UInt8));
end;

procedure DoJmpRIf16_PStk; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  if (PUInt16(PPointer(@Stack[StackPos - SizeOf(Pointer)])^)^ <> 0) then
    JumpToRelative(PInt32(PtrUInt(Code) + ocSize)^)
  else
    Inc(Code, SizeOf(UInt32) + ocSize);
  Dec(StackPos, SizeOf(UInt16));
end;

procedure DoJmpRIf32_PStk; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  if (PUInt32(PPointer(@Stack[StackPos - SizeOf(Pointer)])^)^ <> 0) then
    JumpToRelative(PInt32(PtrUInt(Code) + ocSize)^)
  else
    Inc(Code, SizeOf(UInt32) + ocSize);
  Dec(StackPos, SizeOf(UInt32));
end;

procedure DoJmpRIf64_PStk; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  if (PUInt64(PPointer(@Stack[StackPos - SizeOf(Pointer)])^)^ <> 0) then
    JumpToRelative(PInt32(PtrUInt(Code) + ocSize)^)
  else
    Inc(Code, SizeOf(UInt32) + ocSize);
  Dec(StackPos, SizeOf(UInt64));
end;

procedure DoJmpRIf8_PVar; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_JmpR_PVar(PtrUInt(Code) + ocSize)^ do
    if (PUInt8(PtrUInt(PPointer(@VarStack[VarStackPos + VarStackOffset])^) + PointerOffset)^ <> 0) then
      JumpToRelative(Offset)
    else
      Inc(Code, SizeOf(TOC_JmpR_PVar) + ocSize);
end;

procedure DoJmpRIf16_PVar; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_JmpR_PVar(PtrUInt(Code) + ocSize)^ do
    if (PUInt16(PtrUInt(PPointer(@VarStack[VarStackPos + VarStackOffset])^) + PointerOffset)^ <> 0) then
      JumpToRelative(Offset)
    else
      Inc(Code, SizeOf(TOC_JmpR_PVar) + ocSize);
end;

procedure DoJmpRIf32_PVar; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_JmpR_PVar(PtrUInt(Code) + ocSize)^ do
    if (PUInt32(PtrUInt(PPointer(@VarStack[VarStackPos + VarStackOffset])^) + PointerOffset)^ <> 0) then
      JumpToRelative(Offset)
    else
      Inc(Code, SizeOf(TOC_JmpR_PVar) + ocSize);
end;

procedure DoJmpRIf64_PVar; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_JmpR_PVar(PtrUInt(Code) + ocSize)^ do
    if (PUInt64(PtrUInt(PPointer(@VarStack[VarStackPos + VarStackOffset])^) + PointerOffset)^ <> 0) then
      JumpToRelative(Offset)
    else
      Inc(Code, SizeOf(TOC_JmpR_PVar) + ocSize);
end;

//jump relative if not
procedure DoJmpRIfNot8_Stk; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  if (PUInt8(@Stack[StackPos - SizeOf(UInt8)])^ = 0) then
    JumpToRelative(PInt32(PtrUInt(Code) + ocSize)^)
  else
    Inc(Code, SizeOf(Int32) + ocSize);
  Dec(StackPos, SizeOf(UInt8));
end;

procedure DoJmpRIfNot16_Stk; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  if (PUInt16(@Stack[StackPos - SizeOf(UInt16)])^ = 0) then
    JumpToRelative(PInt32(PtrUInt(Code) + ocSize)^)
  else
    Inc(Code, SizeOf(Int32) + ocSize);
  Dec(StackPos, SizeOf(UInt16));
end;

procedure DoJmpRIfNot32_Stk; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  if (PUInt32(@Stack[StackPos - SizeOf(UInt32)])^ = 0) then
    JumpToRelative(PInt32(PtrUInt(Code) + ocSize)^)
  else
    Inc(Code, SizeOf(Int32) + ocSize);
  Dec(StackPos, SizeOf(UInt32));
end;

procedure DoJmpRIfNot64_Stk; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  if (PUInt64(@Stack[StackPos - SizeOf(UInt64)])^ = 0) then
    JumpToRelative(PInt32(PtrUInt(Code) + ocSize)^)
  else
    Inc(Code, SizeOf(Int32) + ocSize);
  Dec(StackPos, SizeOf(UInt64));
end;

procedure DoJmpRIfNot8_Var; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_JmpR_Var(PtrUInt(Code) + ocSize)^ do
    if (PUInt8(@VarStack[VarStackPos + VarStackOffset])^ = 0) then
      JumpToRelative(Offset)
    else
      Inc(Code, SizeOf(TOC_JmpR_Var) + ocSize);
end;

procedure DoJmpRIfNot16_Var; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_JmpR_Var(PtrUInt(Code) + ocSize)^ do
    if (PUInt16(@VarStack[VarStackPos + VarStackOffset])^ = 0) then
      JumpToRelative(Offset)
    else
      Inc(Code, SizeOf(TOC_JmpR_Var) + ocSize);
end;

procedure DoJmpRIfNot32_Var; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_JmpR_Var(PtrUInt(Code) + ocSize)^ do
    if (PUInt32(@VarStack[VarStackPos + VarStackOffset])^ = 0) then
      JumpToRelative(Offset)
    else
      Inc(Code, SizeOf(TOC_JmpR_Var) + ocSize);
end;

procedure DoJmpRIfNot64_Var; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_JmpR_Var(PtrUInt(Code) + ocSize)^ do
    if (PUInt64(@VarStack[VarStackPos + VarStackOffset])^ = 0) then
      JumpToRelative(Offset)
    else
      Inc(Code, SizeOf(TOC_JmpR_Var) + ocSize);
end;

procedure DoJmpRIfNot8_Ptr; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_JmpR_Ptr(PtrUInt(Code) + ocSize)^ do
    if (PUInt8(Ptr)^ = 0) then
      JumpToRelative(Offset)
    else
      Inc(Code, SizeOf(TOC_JmpR_Ptr) + ocSize);
end;

procedure DoJmpRIfNot16_Ptr; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_JmpR_Ptr(PtrUInt(Code) + ocSize)^ do
    if (PUInt16(Ptr)^ = 0) then
      JumpToRelative(Offset)
    else
      Inc(Code, SizeOf(TOC_JmpR_Ptr) + ocSize);
end;

procedure DoJmpRIfNot32_Ptr; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_JmpR_Ptr(PtrUInt(Code) + ocSize)^ do
    if (PUInt32(Ptr)^ = 0) then
      JumpToRelative(Offset)
    else
      Inc(Code, SizeOf(TOC_JmpR_Ptr) + ocSize);
end;

procedure DoJmpRIfNot64_Ptr; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_JmpR_Ptr(PtrUInt(Code) + ocSize)^ do
    if (PUInt64(Ptr)^ = 0) then
      JumpToRelative(Offset)
    else
      Inc(Code, SizeOf(TOC_JmpR_Ptr) + ocSize);
end;

procedure DoJmpRIfNot8_PStk; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  if (PUInt8(PPointer(@Stack[StackPos - SizeOf(Pointer)])^)^ = 0) then
    JumpToRelative(PInt32(PtrUInt(Code) + ocSize)^)
  else
    Inc(Code, SizeOf(UInt32) + ocSize);
  Dec(StackPos, SizeOf(UInt8));
end;

procedure DoJmpRIfNot16_PStk; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  if (PUInt16(PPointer(@Stack[StackPos - SizeOf(Pointer)])^)^ = 0) then
    JumpToRelative(PInt32(PtrUInt(Code) + ocSize)^)
  else
    Inc(Code, SizeOf(UInt32) + ocSize);
  Dec(StackPos, SizeOf(UInt16));
end;

procedure DoJmpRIfNot32_PStk; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  if (PUInt32(PPointer(@Stack[StackPos - SizeOf(Pointer)])^)^ = 0) then
    JumpToRelative(PInt32(PtrUInt(Code) + ocSize)^)
  else
    Inc(Code, SizeOf(UInt32) + ocSize);
  Dec(StackPos, SizeOf(UInt32));
end;

procedure DoJmpRIfNot64_PStk; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  if (PUInt64(PPointer(@Stack[StackPos - SizeOf(Pointer)])^)^ = 0) then
    JumpToRelative(PInt32(PtrUInt(Code) + ocSize)^)
  else
    Inc(Code, SizeOf(UInt32) + ocSize);
  Dec(StackPos, SizeOf(UInt64));
end;

procedure DoJmpRIfNot8_PVar; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_JmpR_PVar(PtrUInt(Code) + ocSize)^ do
    if (PUInt8(PtrUInt(PPointer(@VarStack[VarStackPos + VarStackOffset])^) + PointerOffset)^ = 0) then
      JumpToRelative(Offset)
    else
      Inc(Code, SizeOf(TOC_JmpR_PVar) + ocSize);
end;

procedure DoJmpRIfNot16_PVar; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_JmpR_PVar(PtrUInt(Code) + ocSize)^ do
    if (PUInt16(PtrUInt(PPointer(@VarStack[VarStackPos + VarStackOffset])^) + PointerOffset)^ = 0) then
      JumpToRelative(Offset)
    else
      Inc(Code, SizeOf(TOC_JmpR_PVar) + ocSize);
end;

procedure DoJmpRIfNot32_PVar; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_JmpR_PVar(PtrUInt(Code) + ocSize)^ do
    if (PUInt32(PtrUInt(PPointer(@VarStack[VarStackPos + VarStackOffset])^) + PointerOffset)^ = 0) then
      JumpToRelative(Offset)
    else
      Inc(Code, SizeOf(TOC_JmpR_PVar) + ocSize);
end;

procedure DoJmpRIfNot64_PVar; {$IFDEF Lape_Inline}inline;{$ENDIF}
begin
  with POC_JmpR_PVar(PtrUInt(Code) + ocSize)^ do
    if (PUInt64(PtrUInt(PPointer(@VarStack[VarStackPos + VarStackOffset])^) + PointerOffset)^ = 0) then
      JumpToRelative(Offset)
    else
      Inc(Code, SizeOf(TOC_JmpR_PVar) + ocSize);
end;