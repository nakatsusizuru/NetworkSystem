for %%i in (*.Proto) do (
    protoc -I=. --proto_path=. --cpp_out=../ %%i
)