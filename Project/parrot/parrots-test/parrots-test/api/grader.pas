program grader;

uses encoder, decoder, gradershare;

var
  N : Longint;
  message : array [0..10000] of Longint;
  MaxExpansion : Longint;
  ChannelRange : Longint;
  
procedure SortMessage(d : Longint);
var
  i,j,b,bi,t : Longint;
begin
  for i:=0 to elength-2 do
  begin
    bi := i;
    b := encoded_message[i];
    for j:=i+1 to elength-1 do
      if ((d=0) and (encoded_message[j] < b)) or
	((d=1) and (encoded_message[j] > b)) then
      begin
	b := encoded_message[j];
	bi := j;
      end;
    t := encoded_message[i];
    encoded_message[i] := encoded_message[bi];
    encoded_message[bi] := t;
  end;
end;

procedure RandomShuffle;
var
  i,p,t : Longint;
begin
  for i:=0 to elength-2 do
  begin
    p := Random(elength-i);
    t := encoded_message[i];
    encoded_message[i] := encoded_message[i+p];
    encoded_message[i+p] := t;
  end;
end;

procedure Shuffle(p :Integer);
begin
  if p = 0 then
    SortMessage(0)
  else if p = 1 then
    SortMessage(1)
  else
    RandomShuffle;
end;

procedure CheckEncodedMessage;
var i : Integer;
begin
  if elength > MaxExpansion * N then
  begin
    WriteLn('Encoded message too long.');
    Halt(0);
  end;
  for i:=0 to elength-1 do
    if (encoded_message[i] < 0) or
      (encoded_message[i] > ChannelRange) then
    begin
      WriteLn('Bad encoded integer');
      Halt(0);
    end;
end;

function CheckOutput: Boolean;
var i : Integer;
begin
  if olength<>N then
    Exit(false)
  else
    for i:=0 to N-1 do
      if output_message[i]<>message[i] then
	Exit(false);
  CheckOutput := true;
end;

var
  i : LongInt;
  tt,t,p,r : LongInt;

begin
  ReadLn(tt);
  ReadLn(MaxExpansion,ChannelRange);
  ReadLn(r); { not used }
  for t:=0 to tt-1 do
  begin
    ReadLn(N);
    for i:=0 to N-1 do
      Read(message[i]);
    ReadLn;
    
    elength := 0;
    encode(N, message);
    CheckEncodedMessage;
    
    ReadLn(p);
    Shuffle(p);
    
    ereadlength := 0;
    olength := 0;
    decode(N, elength, encoded_message);
    if not CheckOutput then
    begin
      WriteLn('Incorrect');
      Halt(0);
    end
  end;
  WriteLn('Correct.');
end.

