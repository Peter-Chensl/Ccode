using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MySql.Data.MySqlClient;

namespace 学生成绩管理系统
{
    public partial class 登录 : Form
    {
        public 登录()
        {
            InitializeComponent();
        }

        private void sign_in_Click(object sender, EventArgs e)
        {
            String username, password;
            username = txtName.Text;
            password = txtpsd.Text;

            String myconn = "server = localhost;port=3306;user=root;password=123456;database=score";//数据库实例连接字符串
            MySqlConnection sq = new MySqlConnection(myconn);//建立连接
            sq.Open();//打开数据库
            if (comboBox1.Text == "学生")
            {
                string sql = string.Format("select count(*) from student where sname='{0}'", username);
                MySqlCommand cmd = new MySqlCommand(sql, sq);
                int a = Convert.ToInt32(cmd.ExecuteScalar());//返回一个值，看用户是否存在
                string sql1 = string.Format("select count(*) from student where spassword='{0}'", password);
                MySqlCommand cmd1 = new MySqlCommand(sql1, sq);
                int b = Convert.ToInt32(cmd1.ExecuteScalar());
                if (a != 0 && b != 0)
                {
                    成绩查询 form = new 成绩查询();
                    form.Show();
                }
                else
                {
                    DialogResult dr = MessageBox.Show("请检查您的用户名或密码是否正确，或注册新用户！", "登录失败!", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                    if (dr == DialogResult.Yes)//打开注册页面
                    {
                        注册 form2 = new 注册();
                        form2.Show();
                    }
                    else
                    {
                        this.Show();
                    }

                }
            }
            if (comboBox1.Text == "教师")
            {
                string sql = string.Format("select count(*) from techer where tname='{0}'", username);
                MySqlCommand cmd = new MySqlCommand(sql, sq);
                int a = Convert.ToInt32(cmd.ExecuteScalar());//返回一个值，看用户是否存在
                string sql1 = string.Format("select count(*) from techer where tpasswoed='{0}'", password);
                MySqlCommand cmd1 = new MySqlCommand(sql1, sq);
                int b = Convert.ToInt32(cmd1.ExecuteScalar());
                if (a != 0 && b != 0)
                {
                    教师 form = new 教师();
                    form.Show();
                }
                else
                {
                    DialogResult dr = MessageBox.Show("请检查您的用户名或密码是否正确，或注册新用户！", "登录失败!", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                    if (dr == DialogResult.Yes)//打开注册页面
                    {
                        注册 form2 = new 注册();
                        form2.Show();
                    }
                    else
                    {
                        this.Show();
                    }

                }
            }
            if (comboBox1.Text == "管理员")
            {
                string sql = string.Format("select count(*) from master where mname='{0}'", username);
                MySqlCommand cmd = new MySqlCommand(sql, sq);
                int a = Convert.ToInt32(cmd.ExecuteScalar());//返回一个值，看用户是否存在
                string sql1 = string.Format("select count(*) from master where mpassword='{0}'", password);
                MySqlCommand cmd1 = new MySqlCommand(sql1, sq);
                int b = Convert.ToInt32(cmd1.ExecuteScalar());
                if (a != 0 && b != 0)
                {
                    管理员 form = new 管理员();
                    form.Show();
                }
                else
                {
                    DialogResult dr = MessageBox.Show("请检查您的用户名或密码是否正确，或注册新用户！", "登录失败!", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                    if (dr == DialogResult.Yes)//打开注册页面
                    {
                        注册 form2 = new 注册();
                        form2.Show();
                    }
                    else
                    {
                        this.Show();
                    }

                }
            }
        }

        private void sign_up_Click(object sender, EventArgs e)
        {
            注册 form = new 注册();
            form.Show();
        }
    }
}
