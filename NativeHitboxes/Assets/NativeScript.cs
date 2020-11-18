using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;


public class NativeScript : MonoBehaviour
{

    // Import and expose native c++ functions

    [StructLayout(LayoutKind.Sequential)]
    public struct Vec2
    {

        public float x;
        public float y;

    }
    [StructLayout(LayoutKind.Sequential)]
    public struct Vec3
    {
        public float x;
        public float y;
        public float z;
    }
    [StructLayout(LayoutKind.Sequential)]
    public struct Vec4
    {
        public float x;
        public float y;
        public float z;
        public float w;
    }
    public Vec2 Vector2ToVec2(Vector2 vec)
    {
        Vec2 vec2 = new Vec2();

        vec2.x = vec.x;
        vec2.y = vec.y;

        return vec2;
    }
    public Vec3 Vector3ToVec3(Vector3 vec)
    {
        Vec3 vec2 = new Vec3();

        vec2.x = vec.x;
        vec2.y = vec.y;
        vec2.z = vec.z;
        return vec2;
    }
    [DllImport("Hitboxes", EntryPoint = "CreateBox")]
    public static extern double CreateBox(Vec3 pos, Vec2 size);
    [DllImport("Hitboxes", EntryPoint = "Add")]
    public static extern int Add(int a, int b);
    // Start is called before the first frame update
    void Start()
    {
        print(CreateBox(Vector3ToVec3(Vector3.down), Vector2ToVec2(new Vector2(1, 1))));
        print(CreateBox(Vector3ToVec3(Vector3.down), Vector2ToVec2(new Vector2(1, 1))));
        print(CreateBox(Vector3ToVec3(Vector3.down), Vector2ToVec2(new Vector2(1, 1))));

    }

    // Update is called once per frame
    void Update()
    {

    }
}

