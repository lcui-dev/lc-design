-- lcui.css 
set_project("lcui.css")

-- xmake minver
set_xmakever("2.1.6")

-- the debug mode
if is_mode("debug") then
    
    -- enable the debug symbols
    set_symbols("debug")

    -- disable optimization
    set_optimize("none")
end

-- the release mode
if is_mode("release") then

    -- enable fastest optimization
    set_optimize("fastest")

    -- strip all symbols
    set_strip("all")
end

target("LCUIEx")
    set_kind("shared")
    set_targetdir("dist/lib")
    add_files("src/*.c")
    add_files("src/ui/*.c")
    add_files("src/ui/components/*.c")
    add_defines("LCUI_EXPORTS")
    add_includedirs("include", "../LCUI/include", "vendor/include")
    on_load(function (target)
        import("lib.detect.find_package")
        target:add(find_package("LCUI", {linkdirs = "vendor/lib"}))
    end)

includes("demo")
