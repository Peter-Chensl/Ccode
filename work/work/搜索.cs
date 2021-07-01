﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MySql.Data.MySqlClient;

namespace work
{
    public partial class 搜索 : Form
    {
        public 搜索()
        {
            InitializeComponent();
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
      
        public void Database_Select_All()
        {

            MySqlDataAdapter mySqlDataAdpter;
            DataSet ds;
            String myconn = "server = localhost;port=3306;user=root;password=123456;database=book";//数据库实例连接字符串
            MySqlConnection sq = new MySqlConnection(myconn);//建立连接
            sq.Open();//打开数据库
            /*string sql = string.Format("select count(*) from books where bookid='{0}'and count != 0 ", this.dataGridView1.CurrentCell.Value);//拼写sql语句删除用户
            MySqlCommand cmd = new MySqlCommand(sql, sq);*/
            try
            {
                Console.WriteLine("查询");
                string sql_select = "select * from books";
                MySqlCommand cmd = new MySqlCommand(sql_select, sq);
                //将查询结果绑定dataview源
                mySqlDataAdpter = new MySqlDataAdapter(cmd);
                ds = new DataSet();
                mySqlDataAdpter.Fill(ds, "books");
                dataGridView1.DataSource = ds;
                dataGridView1.DataMember = "books";
            }
            catch (Exception exception)
            {
                Console.WriteLine(exception);
            }
            finally
            {
                sq.Close();
            }
        }

        private void button1_Click(object sender, EventArgs e)//按书籍号搜索
        {
            MySqlDataAdapter mySqlDataAdpter;
            DataSet ds;
            String myconn = "server = localhost;port=3306;user=root;password=123456;database=book";//数据库实例连接字符串
            MySqlConnection sq = new MySqlConnection(myconn);//建立连接
            sq.Open();//打开数据库
            try
            {
                string sql = string.Format("select * from books where bookid='{0}'", textBox1.Text);
                MySqlCommand cmd = new MySqlCommand(sql, sq);
                mySqlDataAdpter = new MySqlDataAdapter(cmd);
                ds = new DataSet();
                mySqlDataAdpter.Fill(ds, "books");
                dataGridView1.DataSource = ds;
                dataGridView1.DataMember = "books";
            }
            catch(Exception ex)
            {
                Console.WriteLine(ex);
            }
            finally
            {
                sq.Close();
            }
        }

        private void button2_Click(object sender, EventArgs e)//按书名搜索
        {
            MySqlDataAdapter mySqlDataAdpter;
            DataSet ds;
            String myconn = "server = localhost;port=3306;user=root;password=123456;database=book";//数据库实例连接字符串
            MySqlConnection sq = new MySqlConnection(myconn);//建立连接
            sq.Open();//打开数据库
            try
            {
                string sql = string.Format("select * from books where bookname like '%{0}%'", textBox2.Text);
                MySqlCommand cmd = new MySqlCommand(sql, sq);
                mySqlDataAdpter = new MySqlDataAdapter(cmd);
                ds = new DataSet();
                mySqlDataAdpter.Fill(ds, "books");
                dataGridView1.DataSource = ds;
                dataGridView1.DataMember = "books";
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex);
            }
            finally
            {
                sq.Close();
            }
        }

        private void button3_Click(object sender, EventArgs e)//按作者搜索
        {
            MySqlDataAdapter mySqlDataAdpter;
            DataSet ds;
            String myconn = "server = localhost;port=3306;user=root;password=123456;database=book";//数据库实例连接字符串
            MySqlConnection sq = new MySqlConnection(myconn);//建立连接
            sq.Open();//打开数据库
            try
            {
                string sql = string.Format("select * from books where auther like '{0}'", textBox3.Text);
                MySqlCommand cmd = new MySqlCommand(sql, sq);
                mySqlDataAdpter = new MySqlDataAdapter(cmd);
                ds = new DataSet();
                mySqlDataAdpter.Fill(ds, "books");
                dataGridView1.DataSource = ds;
                dataGridView1.DataMember = "books";
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex);
            }
            finally
            {
                sq.Close();
            }
        }

        private void 搜索_Load(object sender, EventArgs e)//窗体加载
        {
            Database_Select_All();
        }
    }
}
