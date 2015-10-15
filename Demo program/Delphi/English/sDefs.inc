{ -------- Definitions by Serge V. Goncharov -------- }
// Freeware lite version of AlphaControls
{.$DEFINE ALITE}
// If used DBGridEH by D. Bolshakov
{.$DEFINE EHLIB}
// If used Interbase components
{.$DEFINE USEIBASE}
// If used database components
{.$DEFINE USEDB}
// For new possibilities testing
{.$DEFINE TEST}
// For sTempates. If project is a demo-application.
{$DEFINE DEMO}
// For TsHintManager easyest using :)
{.$DEFINE EASYHINTS}
{$DEFINE RUNIDEONLY}

{ --------- If one component delivery only --------- }
{.$DEFINE SINGLE}
// If used TsHintManager only
{$IFNDEF ALITE}
{$DEFINE TSHINTS}
{$ENDIF}
// If used TsMenuManager only
{$DEFINE TSMENUS}
{$IFDEF SINGLE}
  {$DEFINE ALITE}
{$ENDIF}
// -------------------------------------------------
{ ---------- End defs by Serge V. Goncharov --------- }

{$IFDEF VER150}
  {$DEFINE COMPILER7}
  {$IFDEF BCB}
    {$DEFINE BCB7}
    {$DEFINE BCB}
  {$ELSE}
    {$DEFINE DELPHI7}
    {$DEFINE DELPHI}
    {$DEFINE DELPHI6UP}
    {$DEFINE DELPHI7UP}
  {$ENDIF}
{$ENDIF}

{$IFDEF VER140}
  {$DEFINE COMPILER6}
  {$IFDEF BCB}
    {$DEFINE BCB6}
    {$DEFINE BCB}
  {$ELSE}
    {$DEFINE DELPHI6}
    {$DEFINE DELPHI}
    {$DEFINE DELPHI6UP}
  {$ENDIF}
{$ENDIF}

{$IFDEF VER130}
  {$DEFINE COMPILER5}
  {$IFDEF BCB}
    {$DEFINE BCB5}
    {$DEFINE BCB}
  {$ELSE}
    {$DEFINE DELPHI5}
    {$DEFINE DELPHI}
  {$ENDIF}
{$ENDIF}

{$IFDEF VER125}
  {$DEFINE COMPILER4}
  {$DEFINE BCB4}
  {$DEFINE BCB}
{$ENDIF}

{$IFDEF VER120}
  {$DEFINE COMPILER4}
  {$DEFINE DELPHI4}
  {$DEFINE DELPHI}
{$ENDIF}

{$IFDEF VER110}
  {$DEFINE COMPILER35}
  {$DEFINE BCB3}
{$ENDIF}

{$IFDEF VER100}
  {$DEFINE COMPILER3}
  {$DEFINE DELPHI3}
  {$DEFINE DELPHI}
{$ENDIF}

{$IFDEF VER93}
  {$DEFINE COMPILER2}
  {$DEFINE BCB1}
  {$DEFINE BCB}
{$ENDIF}

{$IFDEF VER90}
  {$DEFINE COMPILER2}
  {$DEFINE DELPHI2}
  {$DEFINE DELPHI}
{$ENDIF}

{$IFDEF VER80}
  {$DEFINE COMPILER1}
  {$DEFINE DELPHI1}
  {$DEFINE DELPHI}
{$ENDIF}

{$IFDEF DELPHI6UP}
  {$WARN SYMBOL_DEPRECATED OFF}
  {$WARN SYMBOL_PLATFORM OFF}
{$ENDIF}
